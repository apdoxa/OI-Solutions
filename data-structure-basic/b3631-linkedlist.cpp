#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;

	unordered_map<int,int> nextmap;
	nextmap[1]=0;
	while (q--)
	{
		int op;
		cin>>op;

		if (op==1)
		{
			int x,y;
			cin>>x>>y;
			int z=nextmap[x];
			nextmap[x]=y;
			nextmap[y]=z;

		}
		else if (op==2)
		{
			int x;
			cin>>x;
			cout<<nextmap[x]<<'\n';
		}
		else
		{
			int x;
			cin>>x;

			int y=nextmap[x];//x后的数值
			if(y!=0){
				//删除x后面的数值
				nextmap[x]=nextmap[y];
				nextmap.erase(y);
			}	
			
		}
		
	}
	
	return 0;
}