/*****************************************************************************
			Aim  : To convert infix string to postfix.
*****************************************************************************/

#include<stdio.h>
#include<conio.h>
#define n 20

int top = 0;

int p(char op)
{
	switch(op)
	{
	case '$':
		return(10);
		break;
	case '*':
	case '/':
		return(5);
		break;
	case '+':
	case '-':
		return(2);
		break;
	}
}


int empty(char stack[n])
{
	if(top>0)
		return(0);
	else
		return(1);
}

int stacktop(char stack[n])
{
	return(stack[top]);
}

int prec(char op1,char op2)
{
	if(p(op1)>=p(op2))
		return 1;
	else
		return 0;
}

void push(char stack[n],char topsymb)
{
	if(top>n)
		printf("Overflow");
	else
	{
		top++;
		stack[top]=topsymb;
	}
}

int pop(char stack[n])
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
	char stack[n],post[n],input[n];
	char symb,topsymb;
	int i=0,j=0;
	
	printf("Enter infix string : ");
	gets(input);
	
	while(input[i]!='\0')
	{
		symb=input[i];
		if((symb>='a' && symb<='z')||(symb>='A' && symb<='Z'))
		{
			post[j]=symb;
			j++;
		}
		else
		{
			while(!empty(stack) && prec(stacktop(stack),symb))
			{
				topsymb=pop(stack);
				post[j]=topsymb;
				j++;
			}
			push(stack,symb);
		}
		i++;
	}
	
	while(!empty(stack))
	{
		topsymb=pop(stack);
		post[j]=topsymb;
		j++;
	}
	
	post[j]='\0';
	printf("\nPostfix string: ");
	puts(post);
	getch();
}

/******************************** OUTPUT *************************************

	Enter infix string : A+B*C/D$E
  
	Postfix string: ABC*DE$/+
	
*****************************************************************************/
