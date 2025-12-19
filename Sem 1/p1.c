#include<stdio.h>
#include<conio.h>
int main (){
	int row,colmn;
	int i,j,k;

	int arr[5];

	for(i=0; i<5; i++){
		printf("Enter arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	
	
	if(arr[0]<arr[4] && arr[0]<arr[3] && arr[0]<arr[2] &&arr[0]<arr[1]){
		printf("The Smallest Number Among all is arr[0] : %d",arr[0]);
	}
	
	else if(arr[1]<arr[4] && arr[1]<arr[3] && arr[1]<arr[2] &&arr[1]<arr[0]){
		printf("The Smallest Number Among all is arr[1] : %d",arr[1]);
	}
	
	else if(arr[2]<arr[4] && arr[2]<arr[3] && arr[2]<arr[1] &&arr[2]<arr[0]){	
		printf("The Smallest Number Among all is arr[2] : %d",arr[2]);
	}
	
	else if(arr[3]<arr[4] && arr[3]<arr[2] && arr[3]<arr[1] &&arr[3]<arr[0]){
		printf("The Smallest Number Among all is arr[3] : %d",arr[3]);
	}
	
	else if(arr[4]<arr[3] && arr[4]<arr[2] && arr[4]<arr[1] &&arr[4]<arr[0]){
		printf("The Smallest Number Among all is arr[4] : %d",arr[4]);
	}

}
