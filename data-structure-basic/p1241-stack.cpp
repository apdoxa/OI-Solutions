#include <bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<int, bool> matched;
	// To be match stack
	stack<int> left;
	char buf[101];
	cin >> buf;

	int i = 0;
	while (buf[i] != '\0')
	{
		if(buf[i]==')'){
			if(!left.empty()&&buf[left.top()]=='('){
				matched[left.top()]=true;
				matched[i]=true;
				left.pop();
			}
		}else if(buf[i]==']'){
			if(!left.empty()&&buf[left.top()]=='['){
				matched[left.top()]=true;
				matched[i]=true;
				left.pop();
			}
		}else{
			left.push(i);
		}
		i++;
	}

	i = 0;
	while (buf[i] != '\0')
	{
		if(matched[i]){
			cout<<buf[i];
		}else{
			if(buf[i]=='('||buf[i]==')')cout<<"()";
			if(buf[i]=='['||buf[i]==']')cout<<"[]";
		}
		i++;
	}

	return 0;
}