/***************************************************************************
       Aim  : Implementation of Stack using Array.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#define SIZE 3

void push(int *top,int s[SIZE])
{
	if(*top>=SIZE)
		printf("Overflow\n");
	else
	{
		*top=*top+1;
		printf("Enter element: ");
		scanf("%d",&s[*top]);
	}
}

void pop(int *top,int s[SIZE])
{
	if(*top<=0)
		printf("Underflow\n");
	else
	{
		printf("Element Popped: %d\n",s[*top]);
		*top=*top-1;		
	}
}

void display(int *top,int s[SIZE])
{
	int i;
    printf("\n------ STACK ------\n");
	for(i=*top;i>0;i--)
		printf("\t%d\n",s[i]);
    printf("-------------------\n");
}

void main()
{
	int ch;
	int stk[SIZE];
	int top = 0;
	while(ch!=4)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{ 
		case 1:
			push(&top,stk);
			break;
		case 2:
			pop(&top,stk);
			break;
		case 3:
			display(&top,stk);
			break;
		case 4:
			break;
		default:
			printf("Invalid Choice\n");
		}
	}
}
