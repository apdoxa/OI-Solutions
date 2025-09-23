#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    char a[101];
    scanf("%s",&a);
    int i=0;
    while(i<101&&(a[i]!='\0')){
        i++;
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-('a'-'A');
		}
    }
	printf("%s\n",a);
	return 0;
}