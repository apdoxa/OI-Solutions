#include <iostream>
using namespace std;

int g[5][5];
int n = 5;
bool v[5][5];

// 顺时针方向：右→下→左→上（从外向内螺旋）
int dirs[4][2] = {
    {0, 1},    // 右
    {1, 0},    // 下
    {0, -1},   // 左
    {-1, 0}    // 上
};

void spiralDFS(int x, int y, int& count, int direction)
{
    // 边界检查或已访问
    if (x < 0 || y < 0 || x >= 5 || y >= 5 || v[x][y])
    {
        return;
    }
    
    // 访问当前节点
    v[x][y] = true;
    cout << g[x][y];
    if (count % 5 == 0)
        cout << '\n';
    else
        cout << '\t';
    count++;
    
    // 先尝试当前方向
    int nx = x + dirs[direction][0];
    int ny = y + dirs[direction][1];
    
    // 直接递归尝试当前方向（函数开头会检查边界）
    spiralDFS(nx, ny, count, direction);
    
    // 如果当前方向走不通，尝试顺时针转向
    int new_direction = (direction + 1) % 4;
    nx = x + dirs[new_direction][0];
    ny = y + dirs[new_direction][1];
    spiralDFS(nx, ny, count, new_direction);
}

int main()
{
    // 初始化网格
    int num = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            g[i][j] = num;
            num++;
        }
    }

    // 打印原始网格
    cout << "原始矩阵:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << g[i][j] << '\t';
        }
        cout << '\n';
    }

    cout << "\n螺旋遍历顺序:" << endl;
    int count = 1;
    spiralDFS(0, 0, count, 0);  // 从(0,0)开始，初始方向向右

    return 0;
}
