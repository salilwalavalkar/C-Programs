/***************************************************************************
		  Aim  : Array implementation of Linked List.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

struct node
{
	int data;
	int ptr;
}n[SIZE];

int root=-1,avail=0;

void init()
{
	int i;
	for(i=0;i<SIZE-1;i++)
	{
		n[i].ptr=i+1;
		n[i].data=-1;
    }
	n[SIZE-1].ptr=-1;
}

int allocate()
{
	int newnode;
	newnode=avail;
	avail=n[newnode].ptr;
	return newnode;
}

void ins(int val)
{
	int newnode,temp;

	newnode=allocate();
	n[newnode].data=val;
	
	if(avail == -1)
		printf("Array Full");
	else
	{
		if(root==-1)
		{
			root=newnode;
			n[newnode].ptr=-1;
		}
		else
		{
			temp=root;
			while(n[temp].ptr!=-1)
				temp=n[temp].ptr;

			n[temp].ptr=newnode;
			n[newnode].ptr=-1;
		}
	}
}

void rem(int val)
{
	int prev,temp;
	temp=root;
	
	while(temp!=-1)
	{
		prev=temp;
		if(n[temp].data==val)
			break;
		temp=n[temp].ptr;
	}
	
	if(temp==root)
	{
		root=n[temp].ptr;
		avail=temp;
    }
    else
    {
		n[prev].ptr=n[temp].ptr;
		avail=temp;
	}
}

void display()
{
	int temp;
	
	temp=root;
	while(temp!=-1)
	{
		if(n[temp].data!=-1)
			printf("%d<%d>\t",n[temp].data,n[temp].ptr);
		temp=n[temp].ptr;
	}
}

void main()
{
	 int ch;
	 int pos,val;
	 
	 // Initialise
	 init();
	 ///////////

	 while(ch!=4)
	 {
		  system("cls");
		  printf("\n1.Insert\n2.Remove\n3.Display\n4.Exit");
		  printf("\nEnter choice: ");
		  scanf("%d",&ch);
		  switch(ch)
		  {
		   case 1:
				printf("Enter value : ");
				scanf("%d",&val);
				ins(val);
				break;
		   case 2:
				printf("Enter pos : ");
				scanf("%d",&pos);
				//rem(pos);
				getch();
				break;
		   case 3:
			   display();
			   getch();
				break;
		   case 4:
				break;
		  }
	 }
}