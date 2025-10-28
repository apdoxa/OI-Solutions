#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int BLOCK_SIZE = 350; // sqrt(100000) ≈ 316，取350更安全

int n, m;
int block_size, block_cnt;
int sum[MAXN];      // 每个块的开灯数量
bool lazy[MAXN];    // 每个块的懒标记
bool light[MAXN];   // 每个灯的状态

// 获取块编号
inline int get_block(int x) {
    return x / block_size;
}

// 获取块的起始位置
inline int get_start(int block_id) {
    return block_id * block_size;
}

// 获取块的结束位置
inline int get_end(int block_id) {
    return min((block_id + 1) * block_size - 1, n - 1);
}

// 应用懒标记到指定块
void apply_lazy(int block_id) {
    if (lazy[block_id]) {
        int l = get_start(block_id);
        int r = get_end(block_id);
        
        for (int i = l; i <= r; i++) {
            light[i] = !light[i];
        }
        lazy[block_id] = false;
    }
}

// 更新块的开灯数量统计
void update_block_sum(int block_id) {
    int l = get_start(block_id);
    int r = get_end(block_id);
    sum[block_id] = 0;
    
    for (int i = l; i <= r; i++) {
        if (light[i]) {
            sum[block_id]++;
        }
    }
}

// 翻转区间 [l, r]
void flip(int l, int r) {
    int block_l = get_block(l);
    int block_r = get_block(r);
    
    if (block_l == block_r) {
        // 同一个块内
        apply_lazy(block_l);
        for (int i = l; i <= r; i++) {
            light[i] = !light[i];
            sum[block_l] += light[i] ? 1 : -1;
        }
    } else {
        // 处理左边界块
        apply_lazy(block_l);
        int end_l = get_end(block_l);
        for (int i = l; i <= end_l; i++) {
            light[i] = !light[i];
            sum[block_l] += light[i] ? 1 : -1;
        }
        
        // 处理右边界块
        apply_lazy(block_r);
        int start_r = get_start(block_r);
        for (int i = start_r; i <= r; i++) {
            light[i] = !light[i];
            sum[block_r] += light[i] ? 1 : -1;
        }
        
        // 处理中间完整块（ST表式跳步）
        for (int i = block_l + 1; i < block_r; i++) {
            lazy[i] = !lazy[i];
            int block_len = get_end(i) - get_start(i) + 1;
            sum[i] = block_len - sum[i];
        }
    }
}

// 查询区间 [l, r] 的开灯数量
int query(int l, int r) {
    int res = 0;
    int block_l = get_block(l);
    int block_r = get_block(r);
    
    if (block_l == block_r) {
        // 同一个块内
        apply_lazy(block_l);
        for (int i = l; i <= r; i++) {
            if (light[i]) res++;
        }
    } else {
        // 处理左边界块
        apply_lazy(block_l);
        int end_l = get_end(block_l);
        for (int i = l; i <= end_l; i++) {
            if (light[i]) res++;
        }
        
        // 处理右边界块
        apply_lazy(block_r);
        int start_r = get_start(block_r);
        for (int i = start_r; i <= r; i++) {
            if (light[i]) res++;
        }
        
        // 累加中间完整块（ST表式跳步）
        for (int i = block_l + 1; i < block_r; i++) {
            res += sum[i];
        }
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    // 初始化分块
    block_size = sqrt(n);
    block_cnt = (n + block_size - 1) / block_size;
    
    // 初始化所有灯为关闭状态
    memset(light, false, sizeof(light));
    memset(sum, 0, sizeof(sum));
    memset(lazy, false, sizeof(lazy));
    
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        l--; r--; // 转换为0-based
        
        if (op == 0) {
            flip(l, r);
        } else {
            cout << query(l, r) << '\n';
        }
    }
    
    return 0;
}
