#include<stdio.h>
#include<conio.h>
int main (){
	int avg,sum=0;
	int i,j,k;

	int a[5];
	int b[5];
	int c[5];
	
	
	for(i=0; i<5; i++){
		printf("Enter a[%d] : ",i);
		scanf("%d",&a[i]);	
	}
	printf("\n\n");
	for(i=0; i<5; i++){
		printf("Enter b[%d] : ",i);
		scanf("%d",&b[i]);	
	}
	printf("\n\n\n");
	for(i=0; i<5; i++){
		c[i]=a[i]+b[i];
		printf("a[%d] + b[%d] + %d\n",i,i,c[i]);
	}

}
