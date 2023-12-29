#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	
	int T,x,y;
	scanf("%d",&T);
	int test[T][3];
	for(x=0;x<T;x++){
		for(y=0;y<3;y++){
			scanf("%d",&test[x][y]);
		}
	}
	
	for(x=0;x<T;x++){
		int check = 0;
		int ans = test[x][0] / test[x][1];
		if(test[x][0] % test[x][1] == 0) ans--;
		printf("%s\n", ((test[x][2]>=ans) ? "YES" : "NO"));
	}
	
	
	return 0;
}
