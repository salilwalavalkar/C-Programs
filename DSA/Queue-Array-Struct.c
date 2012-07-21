/***************************************************************************
Aim  : Implementation of Queue using Array.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 3

struct queue
{
	int f,r;
	int que[SIZE];
};

void enqueue(struct queue *myq)
{
	if(myq->f==0)
		myq->f=1;
	
	if(myq->r>=SIZE)
		printf("Overflow\n");
	else
	{
		myq->r++;
		printf("\nEnter element: ");
		scanf("%d",&myq->que[myq->r]);
	}
}

void dequeue(struct queue *myq)
{
	if(myq->r>0 && myq->f!=myq->r)
	{
		printf("Element dequeued: %d\n",myq->que[myq->f]);
		myq->f++;
	}
	else if(myq->r<=0)
		printf("Underflow\n");
	else if(myq->r==myq->f)
	{
		printf("Element dequeued: %d\n",myq->que[myq->f]);
		myq->r=0;
		myq->f=0;
	}
}

void display(struct queue *myq)
{
	int i;
	if(myq->r!=0)
	{
		for(i=myq->f;i<=myq->r;i++)
			printf("%d\t",myq->que[i]);
	}
	printf("\n");
}

void main()
{
	int ch;
	struct queue *myq;
	myq=(struct queue *)malloc(sizeof(struct queue));
	myq->f=0;
	myq->r=0;
	while(ch!=4)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			enqueue(myq);
			break;
		case 2:
			dequeue(myq);
			break;
		case 3:
			display(myq);
			break;
		case 4:
			break;
		default:
			printf("Invalid option\n");
		}
	}
}