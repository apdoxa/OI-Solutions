#include <bits/stdc++.h>
using namespace std;
void divide(char *str,int index,int end){
	int idx=end;
	bool find=false;
	while (idx>index)
	{
		if (str[idx]==']')
		{
			find=true;
		}
		if(str[idx]=='[')divide(str,index+1,idx);
		
		idx--;
	}
	if(find){
		for(int i=index;i<end;i++)cout<<str[i];
	}
	
}
int main(){
	const int N=2e4+1;
	char str[N];

	cin>>str;
	int idx=0;
	stack<int> a;
	while (str[idx]!='\0')
	{
		if(str[idx]=='[')divide(str,idx,strlen(str)-1);
		idx++;
	}
	

	return 0;
}