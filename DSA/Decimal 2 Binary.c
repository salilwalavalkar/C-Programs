/***************************************************************************
	Decimal To Binary	
****************************************************************************/

#include<stdio.h>
#include<string.h>

void main()
{
	int n,temp,i;
	int bin[10];
	printf("Enter The Number: \n");
	scanf("%d",&n);

	// Clear contents of bin
	for(i=0;i<7;i++)
		bin[i]=0;

	// Convert & Print Number in Binary
	i=0;
	temp=n;
	while(temp!=0)
	{
		bin[i]=temp%2;
		temp=temp/2;
		i++;
	}
	printf("Number In Binary: ");
	for(i=6;i>=0;i--)
		printf("%d",bin[i]);
}