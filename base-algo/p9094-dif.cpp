#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int Y[N] = {0},B[N] = {0},R[N] = {0};
int dif[N] = {0};

int main()
{
	int ans=0;
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int li, ri, ki;
		cin >> li >> ri >> ki;
		if(ki==1)Y[li]++,Y[ri+1]--;
		if(ki==2)B[li]++,B[ri+1]--;
		if(ki==3)R[li]++,R[ri+1]--;

	}
	for(int i=1;i<=n;i++){
		Y[i]+=Y[i-1];
		B[i]+=B[i-1];
		R[i]+=R[i-1];
	}
	for(int i=1;i<=n;i++){
		if(Y[i]&&B[i]&&!R[i])ans++;
	}
	cout<<ans<<'\n';

	return 0;
}