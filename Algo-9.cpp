#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n,x,y,z,count,temp,prints;
	scanf("%d",&n);
	
	int *arr = (int*)malloc(n*sizeof(int));
	
	for(x=0;x<n;x++){
		scanf("%d",&arr[x]);
	}
	//check for same numbers
	
	for(x=0;x<n;x++){
		count = 0;
		temp = arr[x];
		prints = 1;
		for(x++;temp==arr[x];x++){
			prints++;
		}
		x--;
		for(y=0;y<n;y++){
			if(arr[x] % arr[y] == 0){
				count++;
			}		
		}
		count--;
		for(z=0;z<prints;z++){
			printf("%d ",count);
		}
	}
	return 0;
}
