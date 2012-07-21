/***************************************************************************
       Aim  : Implementation of Stack using Linked List.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define n 3

struct node
{
	int data;
	struct node *ptr;
};

void push(struct node **start,int *nodes)
 {
	struct node *current;
	if(*nodes==n)
		printf("Overflow\n");
	else
	{
		current=(struct node *)malloc(sizeof(struct node));
		printf("Enter element: ");
		scanf("%d",&current->data);
		current->ptr=*start;
		*start=current;
		*nodes=*nodes+1;
	}
 }

void pop(struct node **start,int *nodes)
 {
    struct node *temp;	
    temp=(struct node *)malloc(sizeof(struct node));

	if(*start==NULL)
		printf("Underflow\n");	
	else
	{
		temp=*start;
		*start=temp->ptr;
		printf("Element Popped: %d\n",temp->data);
		free(temp);
		*nodes=*nodes-1;
	}

 }
 
void display(struct node **start)
 {
    struct node *temp;	
    temp=(struct node *)malloc(sizeof(struct node));

	if(*start!=NULL)
	{
		temp=*start;
		printf("\n------ STACK ------\n");
		while(temp!=NULL)
		 {
		  printf("\t%d\n",temp->data);
		  temp=temp->ptr;
		 }
		printf("-------------------\n");
	}
 }

 void main()
 {
	int ch,nodes=0;
    struct node *start=NULL;
	while(ch!=4)
    {
	 printf("\n1.Push\n2.Pop\n3.Display\n");
	 printf("4.Exit\nEnter your choice: ");
	 scanf("%d",&ch);
	 switch(ch)
	 {
	  case 1 :
		 push(&start,&nodes);
		 break;
	  case 2 :
		 pop(&start,&nodes);
		break;
	  case 3 :
		display(&start);
		break;
	  case 4:
		break;
	  default:
		printf("Invalid Choice\n");
	 }
   }
 }