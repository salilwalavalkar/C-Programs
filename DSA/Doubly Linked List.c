/***************************************************************************
		  Aim  : Implementation of Doubly Linked List.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

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
			temp=temp->next;
		 }
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
	int choice,pos,i;
	struct node *current,*temp;	

	while(choice!=4)
	{
		system("cls");
		display(start);
		current=(struct node *)malloc(sizeof(struct node));
		temp=(struct node *)malloc(sizeof(struct node));

		printf("\n1.Beginning\n2.At Position\n3.End\n4.Back");
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: // Beginning
				current->data=input_data();
				current->next=*start;
				*start=current;
				current->prev=*start;
				break;
			case 2: // At Position
				printf("Enter position: ");
				scanf("%d",&pos);
				if(pos==1)
				{
					current->data=input_data();
					current->next=*start;
					*start=current;
					current->prev=*start;
				}
				else
				{
					temp=*start;
					for(i=1;i<pos-1;i++)
					{
						temp=temp->next;
					}					
					current->data=input_data();
					current->next=temp->next;
					current->prev=temp;
					temp->next=current;
				}
				break;
			case 3: // End
				if(*start==NULL)
					*start=current;
				else
				{
					temp=*start;
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=current;
					current->prev=temp;
				}
				current->data=input_data();
				current->next=NULL;
				break;
			case 4:
				break;
		}
	}
}

void delete_node(struct node **start)
{
	int choice,data;
	struct node *prev,*temp;

	while(choice!=4)
	{
		system("cls");
		display(start);
		temp=(struct node *)malloc(sizeof(struct node));
		prev=(struct node *)malloc(sizeof(struct node));

		printf("\n1.Beginning\n2.Having Data\n3.End\n4.Back");
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: // Beginning
					temp=*start;
					if(temp!=NULL)
					{
						*start=temp->next;
						printf("Node %d Deleted\n",temp->data);
						free(temp);
					}
				break;
			case 2: // Having Data
					data=input_data();
					temp=*start;
					if(temp->data==data)
					{
						*start=temp->next;
						printf("Node %d Deleted\n",temp->data);
						free(temp);
					}
					else
					{
						while(temp->next!=NULL)
						{	
							prev=temp;
							temp=temp->next;
							if(temp->data==data)
							{
								prev->next=temp->next;
								printf("Node %d Deleted\n",temp->data);
								free(temp);
								break;
							}
						}
					}
				break;
			case 3: // End
				temp=*start;
				if(temp->next==NULL)
				{
					printf("Node %d Deleted\n",temp->data);
					free(temp);
					*start=NULL;
				}
				else
				{
					while(temp->next!=NULL)
					{
						prev=temp;
						temp=temp->next;
					}
					printf("Node %d Deleted\n",temp->data);
					free(temp);
					prev->next=NULL;
				}
				break;
			case 4:
				break;
		}
	}
}

void search_node(struct node **start)
{
	int pos=1,cnt=0,data;
	struct node *temp;	
	temp=(struct node *)malloc(sizeof(struct node));
	temp=*start;

	data=input_data();

	if(temp->data==data)
	{
		printf("Element found at position %d \n",pos);
		cnt=cnt+1;
	}	
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
			if(temp->data==data)
			{
				pos=pos+1;
				printf("Element found at position %d \n",pos);
				cnt=cnt+1;
			}
		}
	}
	if(cnt==0)
		printf("Element Not Found\n");
}

void main()
{
	 int ch;
	 struct node *start=NULL;
	 start=NULL;
	 while(ch!=5)
	 {
		  system("cls");
		  printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit");
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
				search_node(&start);
				getch();
				break;
		   case 4:
				display(&start);
				getch();
				break;
		   case 5:
			   break;
		   default:
			 printf("Invalid option\n");
		  }
	 }
}