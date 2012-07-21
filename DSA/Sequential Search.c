/***************************************************************************
		Aim  : Implementation of Sequential Search.
****************************************************************************/

#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[10];
	int i,n,element,flag;
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Enter element to search: ");
	scanf("%d",&element);

	// Sequential Search
	i=0;
	while(arr[i]!=element && i<n)
		i++;
	
	if(i<n)
		printf("Element %d found at position: %d",element,i+1);
	else
		printf("Element %d not found",element);
}
