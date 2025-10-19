#include "string.h"
#include "stdlib.h"
#include "stdio.h"
const int N=1e7;
int q_a[10001];
int end=0;
int front=0;
int count=0;

int isEmpty(void){
	return count==0;
}
int isFull(void){
	return count == N;
}
void push_back(int x){
	if(!isFull()){
		
		q_a[end]= x; // 新元素放入当前尾指针位置
		end = (end + 1) % N;  // 循环队列，避免数组越界
		count++;
	}
}
void pop(void){
	if(!isEmpty()){
		front = (front + 1) % N;  // 循环队列
		count--;// 元素数量-1

		if(isEmpty()){
			front=0;
			end=0;
		}
	}else{
		printf("%s\n","ERR_CANNOT_POP");
	}
}
void size(void){
	printf("%d\n",count);
}
void query(void){
	if (!isEmpty())
	{
		printf("%d\n",q_a[front]);
	}else{
		printf("%s\n","ERR_CANNOT_QUERY");
	}
	
}
int main(){
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int op;
			scanf("%d",&op);
			
			switch (op)
			{
			case 1:
				int num;
				scanf("%d",&num);

				push_back(num);
				break;
			case 2:
				pop();
				break;
			case 3:
				query();
				break;
			case 4:
				size();
				break;
			default:
				break;
			}
		}

}