/***************************************************************************
		Aim  : Implementation of Binary Search.
****************************************************************************/

#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[10],i,element;
	int ub,lb,beg,end,mid;
	
	printf("Enter number of elements: ");
	scanf("%d",&ub);
	
	printf("\nEnter elements: ");
	for(i=0;i<ub;i++)
		scanf("%d",&arr[i]);

	printf("Enter element to search: ");
	scanf("%d",&element);

	// Binary Search
	ub--;
	lb=0;
	end=ub;
	beg=lb;
	mid=(beg+end)/2;
	
	while((beg<=end)&&(arr[mid]!=element))
	{
		if(element<arr[mid])
			end=mid-1;
		else
			beg=mid+1;
		
		mid=(beg+end)/2;
	}
	
	if(arr[mid]==element)
		printf("Element %d found at position: %d",element,mid+1);
	else
		printf("Element %d not found",element);
}
