/***************************************************************************
      Aim  : Implementation of Binary Search Tree.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

void add_node(struct node **current,int element)
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
			add_node(&((*current)->left),element);
		else if(element>(*current)->data)
			add_node(&((*current)->right),element);
		else
			printf("\n%d is a duplicate node",element);
	}
}

void del_node(struct node **current,int element)
{
	struct node *temp, *prev, *succ;
	temp = *current;
	
	if(*current == NULL)
		printf("Tree is empty");
	else
	{
		// Search Node
		while(temp->data != element && temp != NULL)
		{
			prev = temp;
			if(temp->data > element)
				temp = temp->left;
			else
				temp = temp->right;
		}

		// Node has 2 Subtrees
		if(temp->left != NULL && temp->right != NULL)
		{
			succ = temp->right;
			while(succ->left != NULL)
			{
				prev = succ;
				succ = succ->left;
			}
			temp->data = succ->data;
			temp = succ;
		}

		// Node has Left Subtree
		if(temp->left != NULL && temp->right == NULL)
		{
			if(prev->left == temp)
				prev->left = temp->left;
			else
				prev->right = temp->left;
		}
		
		// Node has Right Subtree
		if(temp->left == NULL && temp->right != NULL)
		{
			if(prev->left == temp)
				prev->left = temp->right;
			else
				prev->right = temp->right;
		}

		// Node has no Subtrees or Children
		if(temp->left == NULL && temp->right == NULL)
		{
			if(prev->left == temp)
				prev->left = NULL;
			else
				prev->right = NULL;
		}

		// Node is Header
		if(temp == *current)
		{
			if(temp->left != NULL)
				*current = temp->left;
			else
				*current = temp->right;
		}
		
		free(temp);
		printf("\nNode Deleted\n");
	}
}

void search_node(struct node *current,int element)
{
	if(current==NULL)
		printf("Node Not Found.");
	else
	{
		if(element < current->data)
			search_node(current->left,element);
		else if(element > current->data)
			search_node(current->right,element);
		else
			printf("Node Found.");
	}
}

void inorder(struct node *current) // Left - Parent - Root
{
	if(current!=NULL)
	{
		inorder(current->left);
		printf("%d\t",current->data);
		inorder(current->right);
	}
}

void main()
 {
    struct node *root=NULL;
	int n,ch;

	while(ch!=5)
	{
		system("cls");
		printf("\n1.Add Node\n2.Del Node\n3.Search\n4.Display\n5.Exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element:- \n");
				scanf("%d",&n);
				add_node(&root,n);
				break;
			case 2:
				printf("Enter node data:- \n");
				scanf("%d",&n);
				del_node(&root,n);
				break;
			case 3:
				printf("Enter the element:- \n");
				scanf("%d",&n);
				search_node(root,n);
				getch();
				break;
			case 4:
				inorder(root);
				getch();
				break;
			case 5:
				break;
		}
	}
 }