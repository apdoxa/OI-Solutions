#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int n=0;
	char s[51];
	scanf("%d",&n);
	scanf("%s",&s);

	int i=0;
	while (s[i]!='\0')
	{
		int original_offset=s[i]-'a';
		s[i] = 'a'+(original_offset+n)%26;
		i++;
	}
	printf("%s\n",&s);
	return 0;
}