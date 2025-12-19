#include<stdio.h>
#include<conio.h>
int main (){
	int avg,sum=0;
	int i,j,k;

	int arr[10];
	
	for(i=0; i<10; i++){
		printf("Enter arr[%d] : ",i);
		scanf("%d",&arr[i]);
		}
		i=0;
	for(i=0; i<10; i++){
		if(arr[i] % 2 == 0){
			printf("arr[%d] is even number in the given array : %d\n",i,arr[i]);
		}else{
			printf("");
	}
	}
	
	
}
