// Program: Quick Sort.(Recursive)

#include<stdio.h>
#include<conio.h>
int c = 0;

int partition(int data[],int lb,int ub)
{
	int i,j,temp,x;
	c++;
	i=lb+1;
	j=ub;
	x=data[lb];

	while(i<j)
	{
		while(data[i]<x)
			i++;

		while(data[j]>x)
			j--;
		
		if(i<j)
		{
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		}
		else
			break;
	}
	
	data[lb]=data[j];
	data[j]=x;
	return j;
}

void quicksort(int data[],int lb,int ub,int n)
{
	int i,p;

	if(lb<ub)
	{
		p = partition(data,lb,ub);
	
		printf("\nPass %d : ",c);
		for(i=0;i<6;i++)
			printf("%d ",data[i]);

		quicksort(data,lb,p-1,n);

		quicksort(data,p+1,ub,n);
	}
}

void main()
{
	int data[] = {4,2,6,3,5,7};
	int i = 0;

	printf("Original Array : ");
	for(i=0;i<6;i++)
		printf("%d ",data[i]);
	
	quicksort(data,0,6-1,6);

	printf("\n\nFinal Array : ");
	for(i=0;i<6;i++)
		printf("%d ",data[i]);

	getch();
}

/*

	Original Array : 4 2 6 3 5 7
	Pass 1 : 3 2 4 6 5 7
	Pass 2 : 2 3 4 6 5 7
	Pass 3 : 2 3 4 5 6 7

	Final Array : 2 3 4 5 6 7

*/