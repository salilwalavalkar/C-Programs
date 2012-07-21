/***************************************************************************
		Aim  : Implementation of Queue using Linked List.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 3

int f=0,r=0;

struct node
{
	int data;
	struct node *ptr;
};

void enqueue(struct node **start)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	
	if(f==0)
		f=1;
	
	if(r>=SIZE)
		printf("Overflow\n");
	else
	{
		struct node *current;
		current=(struct node *)malloc(sizeof(struct node));
		r=r+1;
		
		if(*start==NULL)
			*start=current;
		else
		{
			temp=*start;
			while(temp->ptr!=NULL)
			{
				temp=temp->ptr;
			}
			temp->ptr=current;
		}
		
		printf("Enter element: ");
		scanf("%d",&current->data);
		current->ptr=NULL;
	}
}

void dequeue(struct node **start)
{
	struct node *temp;	
	temp=(struct node *)malloc(sizeof(struct node));
	
	if(r>0 && f!=r)
	{
		f++;
		temp=*start;
		*start=temp->ptr;
		printf("Element dequeued: %d\n",temp->data);
		free(temp);
	}
	else if(r<=0)
		printf("Underflow\n");
	else if(r==f)
	{
		temp=*start;
		printf("Element dequeued: %d\n",temp->data);
		free(temp);
		*start=NULL;
		r=0;
		f=0;
	}
}

void display(struct node **start)
{
	struct node *temp;	
	temp=(struct node *)malloc(sizeof(struct node));
	
	if(*start!=NULL)
	{
		temp=*start;
		
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->ptr;
		}
	}
}

void main()
{
	int ch;
	struct node *start=NULL;
	while(ch!=4)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			enqueue(&start);
			break;
		case 2:
			dequeue(&start);
			break;
		case 3:
			display(&start);
			break;
		case 4:
			break;
		default:
			printf("Invalid option\n");
		}
	}
}