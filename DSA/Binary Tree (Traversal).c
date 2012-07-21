/***************************************************************************
       Aim  : Implementation of Traversing Methods of Binary Tree.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

void create_node(struct node **current,int element)
{
	if(*current==NULL)
	{
		*current=(struct node *)malloc(sizeof(struct node));
		(*current)->data=element;
		(*current)->left=NULL;
		(*current)->right=NULL;
	}
	else
	{
		if(element<(*current)->data)
			create_node(&((*current)->left),element);
		else if(element>(*current)->data)
			create_node(&((*current)->right),element);
		else
			printf("\n%d is a duplicate node",element);
	}
}

void preorder(struct node *current)	// P - L - R
{
	if(current!=NULL)
	{
		printf("%d\t",current->data);
		preorder(current->left);
		preorder(current->right);
	}
}

void inorder(struct node *current) // L - P - R
{
	if(current!=NULL)
	{
		inorder(current->left);
		printf("%d\t",current->data);
		inorder(current->right);
	}
}

void postorder(struct node *current) // L - R - P
{
	if(current!=NULL)
	{
		postorder(current->left);
		postorder(current->right);
		printf("%d\t",current->data);
	}
}

void main()
 {
    struct node *root=NULL;
	int element,i,n,ch;

	printf("Enter number of nodes: ");
	scanf("%d",&n);
	printf("Enter the elements:- \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&element);
		create_node(&root,element);
	}

	while(ch!=4)
	{
		system("cls");
		printf("\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nPreorder Traversal:\n");
				preorder(root);
				getch();
				break;
			case 2:
				printf("\nInorder Traversal:\n");
				inorder(root);
				getch();
				break;
			case 3:
				printf("\nPostorder Traversal:\n");
				postorder(root);
				getch();
				break;
			case 4:
				break;
		}
	}
 }
 
/***************************** OUTPUT ************************************

		Enter number of nodes: 7
		Enter the elements:-
		4 2 1 3 6 5 7

		1.Preorder
		2.Inorder
		3.Postorder
		4.Exit
		Enter choice: 1

		Preorder Traversal:
		4       2       1       3       6       5       7

		Enter choice: 2

		Inorder Traversal:
		1       2       3       4       5       6       7

		Enter choice: 3

		Postorder Traversal:
		1       3       2       5       7       6       4

*************************************************************************/