/***************************************************************************
	   Aim  : Implementation of Circular Queue using Array.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 3

struct queue
{
	int f,r,count;
	int que[SIZE];
};

void enqueue(struct queue *myq)
{
	if(myq->count==SIZE-1)
		printf("Overflow\n");
	else
	{
		printf("\nEnter element: ");
		scanf("%d",&myq->que[myq->r]);
		myq->r++;
		myq->count++;
	}
	if(myq->r==SIZE)
		myq->r=0;
}

void dequeue(struct queue *myq)
{
 if(myq->count==-1)
    printf("Underflow\n");
 else
   {
		if(myq->f==SIZE-1)
		{
			printf("Element dequeued: %d\n",myq->que[myq->f]);
			myq->que[myq->f]=0;
			myq->f=0;
			myq->count--;
		}
		else
		{
			printf("Element dequeued: %d\n",myq->que[myq->f]);
			myq->que[myq->f]=0;
			myq->f++;
			myq->count--;
		}
	}
	if(myq->r==SIZE)
		myq->r=0;
}

void display(struct queue *myq)
{
	int i;
	if(myq->count==-1)
		printf("Underflow\n");
	else
	{
		for(i=0;i<SIZE;i++)
		{
			if(myq->que[i]!=0)
				printf("%d\t",myq->que[i]);
		}
		printf("\n");
	}
}

void main()
{
	 int i,ch;
	 struct queue *myq;
	 myq=(struct queue *)malloc(sizeof(struct queue));
	 system("cls");
	 myq->f=0;
	 myq->r=0;
	 myq->count=-1;
	 for(i=0;i<SIZE;i++)
		myq->que[i]=0;
	 while(ch!=4)
	 {
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("\nEnter choice: ");
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

/**************************** OUTPUT ***********************************

	1.Enqueue
	2.Dequeue
	3.Display
	4.Exit
	Enter choice: 1
	Enter element: 10

	Enter choice: 1
	Enter element: 20

	Enter choice: 1
	Enter element: 30

	Enter choice: 3
	10	20	30

	Enter choice: 1
	Overflow

	Enter choice: 2
	Element dequeued: 10

	Enter choice: 3
	20	30

	Enter choice: 1
	Enter element: 40

	Enter choice: 3
	40	20	30

************************************************************************/