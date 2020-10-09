#include <stdio.h>
#include <stdlib.h>
void createArray();
void displayArray();
void AppendArray();
void insertArray();
void deleteArray();

//in order to create an Array inside the heap we need to first create a Structure 
struct Array // structure name
{
	int *A; // Array pointer. it is integer type it can point on an Array
	int size; //size of an array that we will enter during run time
	int length; // to store the length of an array i.e: Number of elements that the user wants to enter inside the array
};

//declaring the arr globally will allow us to access it in any function in this program
struct Array arr; /* Initializing the structure (struct Array is not a pointer so we will access the structure members by the use of dot operation)
	                     Example 1. arr.length ; 2. arr.A[i] ; 3. arr.size
	                     if we take arr as a pointer for example struct Array *arr then we will get error messages like :- format specifies type 'int *' but the argument has type 'int' [-Wformat]
                         scanf("%d",arr->A[i]);
                         arr->A method of accessing structure members is only applicable if the structure is a pointer struct Array *arr */

void createArray() //containing the logic for creaton of array with ability to enter the size dynamically during runtime
{
    int n; //n will hold the number of elements that the user wants to insert inside the array
    int i; // Loop variable

    //all the steps here are required for array initialization inside the heap with dinamic memory allocation so that we can enter the size of an array during runtime
	//which allows us to choose the size of an array according to our needs during run time
	
	printf("Enter the size of an array and also the number of elements you want to enter inside the array\n");
	scanf("%d\n",&arr.size); //entering the size of an Array in runtime
	                          // we can only access the struct members using arr there is no other way to do that
    scanf("%d",&n);    // Entering the number of elements the user want to enter inside the array
	arr.A=(int*)malloc(arr.size*sizeof(int)); //created an array inside the heap and making pointer *A point on that array
	arr.length=0; //setting length to zero beacause there are no elements inside array right now
	//........................................................................................................................

    if(n<=arr.size)
    {
    	printf("The capacity of array is %d\n",arr.size);
    	printf("The number of elements user wants to enter inside the array is %d\n",n);
    	//the code below will eneter the elements inside the array
        // by using for loop we will enter the elements inside the array one by one
       printf("Enter the elements inside the Array\n");
       for(i=0;i<n;i++)
       {
    	scanf("%d",&arr.A[i]);
       }
        //setting up the length of an array as n after entering the elements inside the array
        arr.length=n;
    	printf("Array creation Successfull..........\n");
    }
    else
    {
        printf("The number of elements enetered by the user Exceeds the capacity of the Array\n");
    	printf("The capacity of array is %d\n",arr.size);
    	printf("The number of elements user wants to enter inside the array is %d\n",n);
    	printf("Array creation failed..........\n");
    	return;
    }
   //........................................................................................................................
}

void displayArray() //display Array function
{
int i; //loop variable
//now printing the elements entered by the user inside the Array by using for loop again
printf("printing the elements entered by the user inside the Array\n");
    for(int i=0;i<arr.length;i++)
	{
		printf("%d\n",arr.A[i]);
	}
}

void AppendArray()//this Append funtion will insert the element at the end of the array i.e the next free space inside the array
{
	int num; //the number that the user want to append inside the array
	printf("Enter the element that you want to Append inside the array\n");
	scanf("%d",&num);
	if(arr.length!=arr.size)
	{
	  arr.A[arr.length]= num;
	  printf("the appending of %d inside the array is Successfull!!!!.....\n",num);
	  arr.length++; //updating the length of the array
	  printf("The number of elements inside the array is %d\n",arr.length);
	  int free; //it will store the free space present inside the array to store new elements
	  free = arr.size - arr.length;
	  printf("Available space inside the array for new element is %d\n",free);
	  return;
    }
    else
    {
    	printf("Cannot Append the new element %d inside the array because there is no free space\n", num);
    	printf("Maximum array capacity reached!!!!...\n");
    	printf("Array Capacity = %d\n",arr.size);
    	return;
    }

}

void insertArray() //this function will insert the element inside the array at the position givent by the user
{

	int pos; //it will hold the position at which we want to insert the element inside the array
	int i; //loop variable
	int num; //the element you want to insert inside of an array
	int free; //it will store the free space present inside the array to store new elements
	printf("Enter the element you want to insert inside of the array\n");
	scanf("%d",&num);
	printf("Enter the position at which you want to insert the element in the array\n");
	scanf("%d",&pos);
	printf("You want to enter element %d at position %d in the array\n",num,pos);
    if(pos>arr.size)
    {
    	printf("The desired position %d does not exist in the array......\n",pos);
    	printf("Insertion of element %d FAILED!!!!!......\n",num);
    	return;
    }

    if(arr.length!=arr.size)
    {
         for(i=arr.length;i>pos;i--)
         {
         	arr.A[i]=arr.A[i-1]; //it will shift the elements from the last to the desired position by one index
         }
         arr.A[pos]=num; //Inserting the element inside the desired position of the array after shifting all the elements of the array 
         arr.length++; //updating the length of the array
         printf("Insertion of element %d is Successfull!!!!!!!!........\n",num);
         
	     free = arr.size - arr.length; //calculation of free space present inside of an array
	     printf("Available space inside the array for new element is %d\n",free);
	     return;
    }
    else
    {
    	printf("Cannot Insert the new element %d inside the array because there is no free space\n", num);
    	printf("Maximum array capacity reached!!!!...\n");
    	printf("Array Capacity = %d\n",arr.size);
    	return;
    }
}

void deleteArray() //this function will delete the element from the array
{

   int num; //number that you want to delete from the array
   int i; //loop variable for linear search
   int tr=0; // this variable will store true or false value of the state wheater the element is present or not
   int j; //loop variable for shifting mechanism of the elements inside the array
   int free; //it will store the free space present inside the array to store new elements

   printf("Enter the number you want to Delete from the array\n"); //Entering the number that is to be deleted 
   scanf("%d",&num);

   printf("Searching for %d in the array....\n", num);
   for(i=0;i<arr.length;i++)
   {
   	if(num==arr.A[i])
   	{  
   		tr=1;
   		break;
   	}
   }

   if (tr==1)
   {
   	printf("Element %d is in position %d inside the array\n", num,i);
   	printf("Deleting element %d from position %d in the array........\n",num,i);
   	//Applying linear search operation in the array in order to find the element and delete it from the array
   //Linear search is applied here becoz it works on sorted or unsorted array
   	for(j=i;j<arr.length-1;j++)
   	{
   		arr.A[j]=arr.A[j+1]; //it will shift the elements from the last to the desired position by one index
   	}
   	arr.length--; //updating array length
   	free = arr.size - arr.length; //calculation of free space present inside of an array
   	printf("Available space inside the array for new element is %d\n",free);
   	printf("Deletion operation successfull!!!!!!!!!.........\n");
   }
   else if(arr.length==0)
   {
   	printf("The array is empty........\n");
   }
   else
   {
   	printf("Element %d is not present inside the array\n",num);
   	printf("Deletion operation FAILED!!!!!!......\n");
   }
}

int main()
{
	int key; //choice for menue switch case
	int O=0; // menue loop variable
	do
	{
    printf("---------------------------Menue--------------------------------\n");
    printf("Press 1 to Create the Array\n");
    printf("Press 2 to Display the Array\n");
    printf("Press 3 to Append the number inside the array\n");
    printf("Press 4 to Insert the element at the desired position inside the Array\n");
    printf("Press 5 to Delete the element from the array\n");
    printf("Press 6 to Exit the program\n");
    scanf("%d",&key);
    printf("\n");
    switch(key)
    {
    	case 1:
    	createArray(); //create
    	printf("\n");
    	break;
    	case 2:
    	displayArray(); //display
    	printf("\n");
    	break;
    	case 3:
    	AppendArray(); //Append
    	printf("\n");
    	break;
    	case 4:
    	insertArray(); //Insert
    	printf("\n");
    	break;
    	case 5:
    	deleteArray();
    	printf("\n");
    	break;
    	case 6:
    	printf("------------------------Developer info----------------------\n");
    	printf("Name:- Aditya Kumar\n");
    	printf("Course:-B.Tech CS\n");
    	printf("Year:-2nd tear\n");
    	printf("Roll Number:-1901230100001\n");
    	printf("college code:-123\n");
    	printf("\n");
    	printf("Program terminated by the user........\n");
    	O=4000;
    	printf("\n");
    	break;
    	default:
    	printf("wrong choice\n");
    	printf("\n");
    	break;
    }

	}while(O<3000);
	return 0;
}