/***************************************************************************
       Aim  : Implementation of Bubble Sort and Merge Sort.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void bubble()
{
	int a[10],n,i,j,temp;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements:- \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			if(a[i]>a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	
	printf("The sorted elements:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void merge()
{
	int a[10],b[10],c[10];
	int i,j,k,m,n;

	printf("Enter the size of array A: ");
	scanf("%d",&n);
	printf("Enter the elements:- \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("Enter the size of array B: ");
	scanf("%d",&m);
	printf("Enter the elements:- \n");
	for(j=0;j<m;j++)
		scanf("%d",&b[j]);

	i=j=k=0;
	while((i<n)&&(j<m))
	{
		if(a[i]>b[j])
		{
			c[k]=b[j];
			j++;
		}
		else
		{
			c[k]=a[i];
			i++;
		}
		k++;
	}
	
	while(i<n)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	
	while(j<m)
	{
		c[k]=b[j];
		j++;
		k++;
	}
	
	m=m+n;
    printf("The sorted elements:\n");
	for(k=0;k<m;k++)
		printf("%d\t",c[k]);
}

void main()
{
	int ch;
	while(ch!=3)
	{
		system("cls");
		printf("\n1.Bubble Sort\n2.Merge Sort\n3.Exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				bubble();
				getch();
				break;
			case 2:
				merge();
				getch();
				break;
			case 3:
				break;
		}
	}
}