#include <bits/stdc++.h>
using namespace std;
int main() {
	//给庄家的牌
	int a, b;
	cin >> a >> b;
	//发给我的两张牌
	int c, d;
	cin >> c >> d;
	int e;//待发的牌
	cin >> e;

	int suma = a + b;


	if (a == 1 && (suma+10) <=21) {
		suma += 10;
	}
	if (b == 1 && (suma+10) <=21) {
		suma += 10;
	}

	int best = 0;

	//不要
	int sumb1 = c + d;
	if (c == 1 && (sumb1 - 1 + 11) <=21) {
		sumb1 += 10;
	}
	if (d == 1 && (sumb1 - 1 + 11) <=21) {
		sumb1 += 10;
	}
	if (sumb1 <= 21) best = max(best, sumb1);

	//要
	int sumb2 = c + d+e;
	if (c == 1 && (sumb2 - 1 + 11) <=21) {
		sumb2 += 10;
	}
	if (d == 1 && (sumb2 - 1 + 11) <=21) {
		sumb2 += 10;
	}
	if (e == 1 && (sumb2 - 1 + 11) <=21) {
		sumb2 += 10;
	}
	if (sumb2 <= 21) best = max(best, sumb2);

	//分
	if (c == d) {
		// 分不要
		int sumb3 = c;
		if (c == 1 && sumb3 + 10 <= 21) sumb3 += 10;
		if (sumb3 <= 21) best = max(best, sumb3);
		
		// 分要
		int sumb4 = c + e;
		if (c == 1 && sumb4 + 10 <= 21) sumb4 += 10;
		if (e == 1 && sumb4 + 10 <= 21) sumb4 += 10;
		if (sumb4 <= 21) best = max(best, sumb4);
	}
	if(suma>21){
		cout<<"win"<<'\n';
	}else if(best==0){
		cout<<"lost"<<'\n';
	}else if(best>suma){
		cout<<"win"<<'\n';
	}else if(best==suma){
		cout<<"draw"<<'\n';
	}else{
		cout<<"lost"<<'\n';
	}
	
	return 0;
}
