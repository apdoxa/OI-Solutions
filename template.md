# Apdoxa自用板子

> 0.0 2025/10/31

## 目录

### 1. Debug NaN问

#### WA:循环边界，变量命名（重/赋值），循环退出（break?continue?return?）

- a[i]++下一个地址!=a[++i]
- memset单字节赋值，元素用fill

#### RE:vector越界、爆栈、忘记return 0、主函数int main

#### 小技巧

- `-fsanitize`编译参数快速定位越界、未定义问题
- `-fno-omit-frame-pointer`内存错误时打印函数

```
-fsanitize -fno-omit-frame-pointer
```

> sanitizer在对拍时慎用，性能消耗较大

### 2. 数据结构

#### 栈->先进后出

`std::stack`

#### 队列->先进先出

`std::queue` 单向队列	 `std::deque` 双向队列

`std::priority_queue`优先队列(大根堆)，放置操作O(logn)，小根堆->greate

#### 图->点边集合

> G=(V(G),E(G))，其中V(G)是非空集

邻接矩阵 g[x][y] x->y/x-y true,vist[u]=true

邻接表 adj[n]:adj[u]是点u所有出边信息(u->v1,u->v2...)，vist[adj[u]]=true

##### 图的DFS

```cpp
//栈实现
void dfs(int s){
	stack<int> st;
	st.push(s);
	vis[s]=true;
	while(!st.empty()){
		int u=st.top;
		st.pop();
		for(int v:adj[u]){
			if(!vis[v]){
				vis[v]=true;
				st.push(v);
			}
		}
	}
}
//递归
void dfs(const int u){
	vis[u]=true;
	for(int v:adj[u]){
		if...
	}
}
```

##### 图的BFS

stack->队列...
