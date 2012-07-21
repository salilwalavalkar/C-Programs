/***************************************************************************
	  Aim  : Implementation of Queue using Array
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#define SIZE 3

int f=0,r=0;
int que[SIZE];

void enqueue()
{
	if(f==0)
		f=1;
	
	if(r>=SIZE)
		printf("Overflow\n");
	else
	{
		r=r+1;
		printf("\nEnter element: ");
		scanf("%d",&que[r]);
	}
}

void dequeue()
{
	int i;
	if(r>0 && f!=r)
	{
		printf("Element popped: %d\n",que[f]);
		f++;
	}
	else if(r<=0)
		printf("Underflow\n");
	else if(r==f)
	{
		printf("Element popped: %d\n",que[f]);
		r=0;
		f=0;
	}
}

void display()
{
	int i;
	if(r!=0)
	{
		for(i=f;i<=r;i++)
			printf("%d\t",que[i]);
	}
	printf("\n");
}

void main()
{
	int ch;
	while(ch!=4)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		default:
			printf("Invalid option\n");
		}
	}
}