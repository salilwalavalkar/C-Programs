/*****************************************************************************
			Aim  : To convert Postfix to Infix
*****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define n 20

int top = 0;

int oper(char op,int op1,int op2)
{
	switch(op)
	{
	case '+':
		return op1+op2;
	case '-':
		return op1-op2;
	case '*':
		return op1*op2;
	case '/':
		return op1/op2;
	}
}

void push(int stack[n],int topsymb)
{
	if(top>n)
		printf("Overflow");
	else
	{
		top++;
		stack[top]=topsymb;
	}
}

int pop(int stack[n])
{
	if(top==0)
		return 0;
	else
	{
		top--;
		return(stack[top+1]);
	}
}

void main()
{
	int stack[n];
	char symb,input[n];
	int i=0,j=0,ans=0;
	int p1,p2;
	printf("Enter postfix string : ");
	gets(input);

	while(input[i]!='\0')
	{
		symb=input[i];
		if(isdigit(symb))
			push(stack,symb-48);
		else
		{
			p1=pop(stack);
			p2=pop(stack);
			ans=oper(symb,p1,p2);
			push(stack,ans);
		}
		i++;
	}
	printf("\nInfix string: ");
	printf("Ans= %d",ans);
	getch();
}

/******************************** OUTPUT *************************************

		Enter postfix string : 324+*

		Infix string: Ans= 18
	
*****************************************************************************/