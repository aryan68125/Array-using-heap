#include<stdio.h>
#include<stdlib.h>
int main()
{
	//Array inside a stack is called Static Array
	int A[5]={2,4,6,8,10}; //declaring array of size 10 and then initializing it with the values in run time
	
	//Array inside a heap is called Dynamic Array
	//declaring another array inside heap and accessing its data using a pointer
	int *p; //pointer variable pointing towards the array inside heap
    p = (int*) malloc(5*sizeof(int));
    //initializing the array inside the heap and assigning values inside the array
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    int i; //loop variable which will be used to display the variable of the arrays

    //printing the array A
    printf("Printing Array A\n");
    for(i=0;i<5;i++)
    {
    	printf("%d\n",A[i]);
    }

    //printing the array inside that heap using pointer p
    printf("Printing Array B\n");
    for(i=0;i<5;i++)
    {
    	printf("%d\n",p[i]);
    }

    return 0;
}