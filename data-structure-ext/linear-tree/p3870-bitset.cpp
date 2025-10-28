//TODO:fix
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n,m;
	const int BITLEN=1e5+10;
	bitset<BITLEN> bmap;
	cin>>n>>m;

	while (m--)
	{
		bitset<BITLEN> aaa;
		bitset<BITLEN> b;
		b.set(1);
		aaa.set();
		int op,a,b;
		cin>>op>>a>>b;
		if(op==0){
			aaa<<=(BITLEN);
			~aaa;
			bmap ^=aaa;
		}else{
			//out
		}
		
	}
	


	return 0;
}