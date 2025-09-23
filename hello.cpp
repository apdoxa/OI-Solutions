#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

void bubble_sort(vector<long long> *arrary,int n){
	__int128 b;
	printf("%lld",b);
	for(int i=0;i<n-1;i++){
		if ((*arrary)[i+1]<(*arrary)[i]) {
			long long t;
			t=(*arrary)[i];
			(*arrary)[i]=(*arrary)[i+1];
			(*arrary)[i+1]=t;

		}
	}
}

int main() {
	vector<long long> arrary;
	arrary.push_back(1);
	arrary.push_back(3);
	arrary.push_back(6);
	arrary.push_back(1);
	arrary.push_back(2);

	int n=5;
	bubble_sort(&arrary, n);
	
	for (int i=0;i<5;i++) {
		printf("%lld",arrary[i]);
	}
	return 0;
}