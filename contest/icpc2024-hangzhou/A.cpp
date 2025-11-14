#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int pa[26];
int find(int x){
	if(pa[x]!=x){
		pa[x]=find(pa[x]);//找上级，归
	}
	return pa[x];
}
void unite(int x,int y){
	int pa_x=find(x);
	int pa_y=find(y);
	if(pa_x!=pa_y){
		//x和y的父节点不同
		//那么我们就把x的父节点归入y的父节点之下，从而实现合并
		pa[pa_x]=pa_y;
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s1, s2, s3;

		cin >> s1 >> s2 >> s3;
		//初始化并查集
		for(int i=0;i<26;i++){
			pa[i]=i;
		}
		if (s1.length() != s2.length()) {
			cout << "NO" << endl;
			continue;
		}
		if (s1.length() != s3.length()) {
			cout << "YES" << endl;
			continue;
		}
		for(int i=0;i<s1.length();i++){
			int u=s1[i]-'a';
			int v=s2[i]-'a';
			unite(u,v);//将1和2映射到同一节点
		}
		bool found_diff=false;
		for(int i=0;i<s1.length();i++){
			int u=s1[i]-'a';
			int v=s3[i]-'a';
			if(find(u)!=find(v)){
				//s1和s3归属不同,有差异，该输出YES
				found_diff=true;
			}
		}
		
		if(found_diff){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}
