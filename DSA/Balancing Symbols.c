/*	Balancing Symbols	*/

#include<stdio.h>
#include<conio.h>
#define MAX 20

int top=0;
char stk[MAX];

int chk_match(char ch,char symb)
{
	if(ch=='(' && symb==')')
		return 1;
	else if(ch=='[' && symb==']')
		return 1;
	else if(ch=='{' && symb=='}')
		return 1;
	else 
		return 0;
}

int pop()
{
	if(top==0) 
		return 1;
	else
	{
		top--;
		return stk[top+1];
	}
}

void push(char symb)
{
	if(top==MAX) 
		printf("Overflow\n");
	else
	{
		top++;
		stk[top]=symb;
	}
}

void main()
{
	int i,valid=0;
	char symb[20],ch;
	printf("Enter The Expression\n");
	scanf("%s",&symb);
	
	// Check Expression
	i=0;
	while(symb[i]!='\0')
	{
		if(symb[i]=='('||symb[i]=='['||symb[i]=='{')
			push(symb[i]);
		
		if(symb[i]==')'||symb[i]==']'||symb[i]=='}')
		{
			if(top==0)
			{
				valid=1;
				break;
			}
			else
			{
				ch=pop();
				if(chk_match(ch,symb[i])==0)
				{
					valid=1;
					break;
				}
			}
		}
		i++;
	}
	////////////////////

	if(top==0 && valid==0)
		printf("String is valid\n");
	else
		printf("String is Invalid\n");
}