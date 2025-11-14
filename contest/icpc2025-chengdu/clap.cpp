#include <bits/stdc++.h>
using namespace std;
int main(){
	int cnt=0;
	while(true){
		printf("running on #%d",cnt);
		system("./gen > 1.in");
		auto t1=chrono::high_resolution_clock::now();
		system("./brute < 1.in > 1.ans");
		auto t2=chrono::high_resolution_clock::now();
		system("./code < 1.in > 1.out");
		auto t3=chrono::high_resolution_clock::now();
		auto res=system("diff -w 1.ans 1.out");
		if(res){
			printf("WA\n");
			return 0;
		}else{
			cnt++;
			printf("AC b%lfms c%lfdms",(t2-t1).count()/1e6,(t3-t2).count()/1e6);
		}
	}
	
	return 0;
}
