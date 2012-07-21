/***************************************************************************
		  Aim  : Implementation of Circular Link List
****************************************************************************/
// All Working

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *ptr;
};

void display(struct node **start)
{
	struct node *temp;	
	temp=(struct node *)malloc(sizeof(struct node));

	if(*start!=NULL)
	{
		temp=*start;
		
		while(temp->ptr!=*start)
		 {
			printf("%d\t",temp->data);
			temp=temp->ptr;
		 }
		printf("%d\t",temp->data);
	}
}

int input_data()
{
	 int data;
	 printf("Enter element: ");
	 scanf("%d",&data);
	 return(data);
}

void insert_node(struct node **start)
{

	int choice;
	struct node *current,*temp;	

	while(choice!=3)
	{
		system("cls");
		display(start);
		current=(struct node *)malloc(sizeof(struct node));
		//temp=(struct node *)malloc(sizeof(struct node));

		printf("\n1.Beginning\n2.End\n3.Back");
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: // Beginning
				current->data=input_data();
				if(*start==NULL)
				{
					*start=current;
					current->ptr=*start;
				}
				else
				{
					// Modify adddress of Last Node.
					temp=*start;
					while(temp->ptr!=*start)
					{
						temp=temp->ptr;
					}
					//////////

					current->ptr=*start;
					*start=current;
					temp->ptr=*start;
				}
				break;
			case 2: // End
				if(*start==NULL)
				{
					*start=current;
					current->ptr=*start;
				}
				else
				{
					temp=*start;
					while(temp->ptr!=*start)
					{
						temp=temp->ptr;
					}

					temp->ptr=current;
					current->ptr=*start;
				}
				current->data=input_data();
				break;
			case 3:
				break;
		}
	}
}

void delete_node(struct node **start)
{
	int choice;
	struct node *prev;
	struct node *temp1,*temp2;

	while(choice!=3)
	{
		system("cls");
		display(start);
		//prev=(struct node *)malloc(sizeof(struct node));
		//temp1=(struct node *)malloc(sizeof(struct node));
		//temp2=(struct node *)malloc(sizeof(struct node));

		printf("\n1.Beginning\n2.End\n3.Back");
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: // Beginning
				temp1=*start;
				if(temp1->ptr==*start)
				{
					printf("Node %d Deleted\n",temp1->data);
					free(temp1);
					*start=NULL;
				}
				else
				{
					temp1=*start;
					temp2=*start;

					if(temp1!=NULL)
					{
						// Modify adddress of Last Node.
						while(temp1->ptr!=*start)
						{
							temp1=temp1->ptr;
						}
						
						*start=temp2->ptr;
						temp1->ptr=*start;
						
						printf("Node %d Deleted\n",temp2->data);
						free(temp2);
						///////////////////////////////
					}
				}
				break;
			case 2: // End
				temp1=*start;
				if(temp1->ptr==*start)
				{
					printf("Node %d Deleted\n",temp1->data);
					free(temp1);
					*start=NULL;
				}
				else
				{
					while(temp1->ptr!=*start)
					{
						prev=temp1;	
						temp1=temp1->ptr;
					}
					prev->ptr=temp1->ptr;
					//printf("Node %d Deleted\n",temp1->data);
					free(temp1);
				}
				break;
			case 3:
				break;
		}
	}
}

void main()
{
	 int ch;
	 struct node *start=NULL;
	 start=NULL;
	 while(ch!=4)
	 {
		  system("cls");
		  printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
		  printf("\nEnter choice: ");
		  scanf("%d",&ch);
		  switch(ch)
		  {
		   case 1:
				insert_node(&start);
				break;
		   case 2:
				delete_node(&start);
				break;
		   case 3:
				display(&start);
				getch();
				break;
		   case 4:
			   break;
		   default:
			 printf("Invalid option\n");
		  }
	 }
}