#include "stdio.h"
const int N = 200001;
int main()
{
	int top = -1, a[N];
	//开一个最大数的栈
	int max_top = -1, max_a[N];

	int n = 0;

	int max = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int op_code;
		scanf("%d", &op_code);
		switch (op_code)
		{
		case 0:
			int w;

			scanf("%d", &w);
			top++;
			a[top]=w;
			//比较最大值栈顶
			if(max_top==-1||w >= max_a[max_top]){
				max_top++;
				max_a[max_top]=w;
			}

			break;
		case 1:
			if(top==-1)break;
			if(a[top]==max_a[max_top]){
				max_top--;
			}
			top--;
			break;
		case 2:
			if(max_top==-1){
				printf("0\n");
			}else{
				printf("%d\n",max_a[max_top]);
			}
			break;

		default:
			break;
		}
	}
}