#include <bits/stdc++.h>
using namespace std;

char str[20002];
int len;

string dfs(int &idx) {
    string result;
    while (idx < len && str[idx] != ']') {
        if (str[idx] == '[') {
            idx++; // 跳过[
            
            int count = 0;
            while (isdigit(str[idx])) {
                count = count * 10 + (str[idx] - '0');
                idx++;
            }
            
            // 递归
            string sub = dfs(idx);
            idx++; // 跳过']'
            
            for (int i = 0; i < count; i++) {
                result += sub;
            }
        } else {
            result += str[idx];
            idx++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> str;
    len = strlen(str);
    int idx = 0;
    cout << dfs(idx);
    return 0;
}
