#include <cstdio>
#include <iostream>
#define  N (int)(1e6+1)
using namespace std;
unsigned long long st[N];
unsigned long long p=0;
inline void pop(){
	p--;
}
inline void push(unsigned long long x){
	st[p++]=x;
}
inline unsigned long long top(){
	return st[p-1];
}
inline unsigned long long size(){
	return p;
}

int main(){

	int T,n;
	cin>>T;
	for(int i=0;i<T;i++){
		p=0;
		cin>>n;
		for(int j=0;j<n;j++){
			string o;
			cin>>o;
			if (o=="push")
			{
				unsigned long long str;
				cin>>str;
				push(str);
			}
			else if (o=="pop")
			{
				if(p==0){
					cout << "Empty\n";
				}else{
					pop();
				}
			}
			else if(o=="query")
			{
				if(p==0){
					cout << "Anguei!\n";
				}else{
					cout<<top()<<'\n';
				}
				
			}else if(o=="size"){
				cout<<size()<<'\n';
			}
			
		}
	}
	return 0;
}