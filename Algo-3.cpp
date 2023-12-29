#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int isSet(int arr[], int size);

int main(){
	
	int T,x,y,z,op,a,b;
	scanf("%d",&T);
	int len[T];
	char eq[T][20];
	for(x=0;x<T;x++){
		scanf("%d",&len[x]);
		scanf("%s",eq[x]);
	}
	
	for(x=0;x<T;x++){
		//check operator
		op=0;
		for(y=0;eq[x][y]!='\0';y++){
			if(eq[x][y]=='+') op = 1;
			else if(eq[x][y]=='-') op = 2;
			else if(eq[x][y]=='*') op = 3;
			else if(eq[x][y]=='/') op = 4;
			if(op!=0) break;
		}
		//check num digits of operands
		int operandLength[3]= {0};
		for(y=0;eq[x][y]>='A' && eq[x][y]<='Z'; y++){
			operandLength[0]++;
		}
		for(y++;eq[x][y]>='A' && eq[x][y]<='Z'; y++){
			operandLength[1]++;
		}
		for(y++;eq[x][y]>='A' && eq[x][y]<='Z'; y++){
			operandLength[2]++;
		}
		int numChars = operandLength[0]+operandLength[1]+operandLength[2];
		
		int arr[numChars][4];
		// 0-letter, 1-Operand#(1-3), 2-Place value(0-...), 3-value
		// input letter details
		z=0;
		for(y=0;eq[x][y]!='\0';y++){
			if(eq[x][y]>='A' && eq[x][y]<='Z'){
				arr[y][0] = eq[x][y];
				arr[y][1] = z;
				arr[y][2] = --operandLength[z];
			}else{
				z++;
			}
		}
		// sort the rows (by letter)
		int (*temp)[4];
		for(a=0;a<len[x]-1;a++){
			for(b=a;b<len[x]-a-1;b++){
				if(arr[a][0] < arr[b][0]){
					memcpy(temp,arr[a],4*sizeof(int));
					memcpy(arr[a],arr[b],4*sizeof(int));
					memcpy(arr[b],temp,4*sizeof(int));
				}
			}
		}
		// loop for the digits
		int vals[(len[x])];
		for(a=0;a<len[x];a++){ //initialize
			vals[a]=a;
		}
		int is_true = 0;
		while (is_true == 0){
			
			//check if digits in vals array is unique
			while(isSet(vals,len[x]) == 0){
				vals[len[x]-1]++;
				checkOverflow(vals,len[x]);
			}	
			
			//feed the digits in the letters/place values
			int operands[3] = {0};
			char ch = 0;
			b=-1;
			for(a=0;a<numChars;a++){
				if(eq[a][0] != ch) b++;
				ch = eq[a][0];
				eq[a][3] = len[b];
				
			}
			
			//compute and verify
			for(a=0;a<numChars;a++){
				if(eq[a][0] != ch) b++;
				ch = eq[a][0];
				eq[a][3] = len[b];
			}
			
			vals[len[x]-1]++;
		}
		
		//copy the result of the digit equivalent to a temporary array of strings
		
	}
	
	//sort the letters in T test cases (temporary array of strings)
	
	
	//display result
	
	
	return 0;
}

int isSet(int arr[], int size){
	int isUnique = 1;
	int x,y;
	for(x=0;x<size && isUnique == 1;x++){
		for(y=x;y<size && arr[x]!=arr[y];y++){}
		if(y<size) isUnique=0;
	}
	return isUnique;
}

void checkOverflow(int arr[], int size){
	int x;
	for(x=size-1;x>0;x++){
		if(arr[x] == 10){
			arr[x] = 0;
			arr[x-1]++;
		}
	}
}
