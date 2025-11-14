#include <bits/stdc++.h>
using namespace std;
int main(){
	double s,v;
	cin>>s>>v;
	//more clearly
	int total=ceil(s/v)+10;
	int before=8*60-total;

	if(before<0)before+=24*60;//加上一天
	int h=before/60,m=before%60;
	if(h<10)cout<<'0';
	cout<<h<<':';
	if(m<10)cout<<'0';
	cout<<m<<'\n';

	// int dur=ceil(s/v)+10;
	// //8:00
	// int h=8-ceil((dur)/60.0),m=0-(dur%60);
	// if(h<0)h+=24;
	// if(m<0)m+=60;
	// if(h<10)cout<<'0';
	// cout<<h<<':';
	// if(m<10)cout<<'0';
	// cout<<m<<'\n';
}
