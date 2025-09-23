#include <bits/stdc++.h>
using namespace std;
const int N=10e5;
struct Stack{
	int top,a[N];
	void init(){
		top=0;
	}
	void pop(){
		if(top)top--;
	}
	void push(int x){
		a[++top]=x;
	}
	int empty(){
		if(top>0){
			return 0;
		}else{
			return 1;
		}
	}
	int head(){
		return a[top];
	}
};
//Scan solution
void scan_solution(){
	char c;
	cin>>c;
	int no_matched=0;

	int i=0;
	// 逐个字符输入
	while (c!='@')
	{

		if(i==0&&c==')'){
			cout<<"NO";
			return;
		}
		if(c=='(')no_matched++;
		if(c==')')no_matched--;
		
		if(no_matched<0){
			cout<<"NO";
			return;
		}
		i++;
		cin>>c;
	}
	if(!no_matched){
		cout<<"YES";return;
	}else{
		cout<<"NO";return;
	}
	
}
// Stack solution
void stack_solution()
{
	char c[257];
	Stack s;
	s.init();

	// 逐个字符输入
	cin >> c;
	int i=0;
	while (c[i] != '@')
	{
		if (s.empty())
		{
			// 第一个）必错
			if (c[i] == ')')
			{
				cout << "NO";
				return;
			}
		}
		if (c[i] == '(')
			s.push(true);
		if (c[i] == ')')
			s.pop();
		i++;
	}
	if (s.empty())
		cout << "YES";
	else
		cout << "NO";
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack_solution();
	return 0;
}