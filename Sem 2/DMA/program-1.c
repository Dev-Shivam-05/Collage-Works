#include<stdio.h>
#include<stdlib.h>

void insertElements();
void insertElementAtEnd();
void updateElement();
void deleteElements();
void displayElements();

int main() {
	int size = NULL;
	int *array = NULL;
	
	printf("Enter The Size Of The Array :- ");
	scanf("%d",&size);
	
	array = (int*)malloc(size * sizeof(int));
	
	int choice;
	do{
		printf("1. To Insert An Element At The End Of the Array.");
		printf("2. To Update Element In the Array.");
		printf("3. To Delete Element In the Array.");
		printf("4. To Display Element In the Array.");
		printf("0. To Exit");
		printf("Enter Your Choice :- ");
		
		switch (choice) {
			case 0: 
				printf("The Program Is Successfully Executed.");
				break;
			case 1: 
				insertElements(array,size);
				break;
			case 2: 
				updateElement(array,size);
				break;
			case 3: 
				deleteElements(array,size);
				break;
			case 4: 
				displayElements(array,size);
				break;
			default:
				printf("Wrong Choice....");
				break;
		}
	} while (choice != 0)
	free(array);
}

void insertElements(int array[],int size) {
	for(int i = 0; i < size; i++) {
		printf("%d",array[i]);	
		scanf("%d",&array[i]);
	}
}

void displayElements(int array[],int size) {
	printf("Current Array IS :- \n");
	for(int i = 0; i < size; i++) {
		printf("%d ",array[i]);	
	}
}


void insertElementAtEnd(int array[],int size) {
	int element;
	printf("Enter Element To Insert :- ");
	scanf("%d",&element);
	size++;
	array = realloc(array, size * sizeof(int));
	array[size-1] = element;
}

void deleteElements(int array[],int size) {
	free(array[size]);
	size--;

	printf("last Item Is Successfully Removed.");
}

void updateElement(int array[],int size) {
	int element,index;
	displayElements(array,size)
	printf("Enter index To Target :- ");
	scanf("%d",&index);
	if(index >= 0 && index < size){
		printf("Enter Element To Update at %d Index :- ",index);
		scanf("%d",&element);
		array[index] = element;
	}
	else {
		printf("Wrong index Please Try Again.");
	}
	printf("The Value %d is Successfully Replaced At Index %d.",element,index);
}

