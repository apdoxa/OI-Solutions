#include <bits/stdc++.h>
#define fft(i,x) for (int i = 1; i <= x; i++)
using namespace std;
const int MAXN = 1e5;
int LogN[MAXN];

void pre()
{
	// LogN表
	LogN[1]=0;
	LogN[2]=1;
	for(int i=3;i<=MAXN;i++){
		LogN[i]=LogN[i/2]+1;
	}
}
int main()
{

	int stb[20][MAXN];

	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	pre();
	fft(i,n)
	{
		cin >> stb[0][i];
	}
	fft(i,LogN[n]+1){
		for (int j = 1; j +(1ULL<<i)-1<=n; j++)
		{
			stb[i][j]=max(stb[i-1][j],stb[i-1][j+(1ULL<<(i-1))]);//从上一层推下一层 2^(k) k=0~j,恰大于的幂
		}
	}
	fft(i,m){
		int x,y;
		cin>>x>>y;
		int len=LogN[y-x+1];
		cout<<max(stb[len][x],stb[len][y-(1ULL<<len)+1])<<'\n';
	}

	return 0;
}