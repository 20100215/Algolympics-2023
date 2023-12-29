#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	
	int D, N, x, y;
	scanf("%d",&D);
	scanf("%d",&N);
	int A[D];
	for(x=0;x<D;x++){
		scanf("%d",&A[x]);
	}
	int B[D];
	for(x=0;x<D;x++){
		scanf("%d",&B[x]);
	}
	int keepers[N][D];
	for(x=0;x<N;x++){
		for(y=0;y<D;y++){
			scanf("%d",&keepers[x][y]);
		}
	}
	
	for(x=0;x<N;x++){
		for(y=0;y<D && keepers[x][y] >= (A[y]-B[y]) && keepers[x][y] <= A[y]; y++){}
		printf("%s\n", ((y<D) ? "INNOCENT" : "SUS"));
	}
	
	
	return 0;
}
