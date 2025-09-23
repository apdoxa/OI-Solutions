#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void insert_sort(int *arr,int n){
	for (int i = 1; i < n; i++)
	{
		int key=arr[i];
		int j=i-1;
		while (j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	
}
void select_sort(int *arr,int n){
	for(int i=0;i<n;i++){
		int min_idx=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min_idx])min_idx=j;//找出[i+1,n-1]中最小的数其索引
		}
		int t=arr[i];
		arr[i]=arr[min_idx];
		arr[min_idx]=t;
		for(int i=0;i<n;i++){
			printf("%d\t",arr[i]);
		}
		printf("\n");
	}
}
void count_sort(int *arr,int n){
	int cnt[101];
	memset(cnt,0,sizeof(cnt));

	for(int i=0;i<n;i++){
		cnt[arr[i]]++;
	}
	int idx=0;
	for(int i=0;i<101;i++){
		while (cnt[i]>0)
		{
			arr[idx]=i;
			idx++;
			cnt[i]--;
		}
		
	}
}
void bubble_sort(int *arr,int n){
	for(int i=0;i<n;i++){
		bool swp=false;
		for(int j=0;j<n-i-1;j++){
			printf("j=%d\t",j);
			if(arr[j]<arr[j+1]){
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
				swp=true;
			}
		}
		for(int i=0;i<5;i++){
			printf("%d\t",arr[i]);
		}
		cout<<'\n';
		if(!swp)break;
	}

}
int main(){
	int arr[10];
	for (int i = 0; i < 5; i++)
	{
		cin>>arr[i];
	}
	insert_sort(arr,5);
	for(int i=0;i<5;i++){
		printf("%d\t",arr[i]);
	}
	
}