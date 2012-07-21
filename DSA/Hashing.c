/***************************************************************************
		Aim  : Implementation of Hashing Function.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int arr[10],ch,data,rem,i,j,n=5;
	
	// Reset Array Values
	for(i=0;i<n;i++)
		arr[i]=0;

	while(ch!=3)
	{
		system("cls");
		printf("\n1.Input Data\n2.View Data\n3.Exit");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter data: ");
				scanf("%d",&data);
				
				//Calculate Address
				rem=data % n;
				if(arr[rem]==0)
				{
					arr[rem]=data;
					printf("\nData Entered");
				}
				else
				{
					j=rem+1;
					while(j!=rem)
					{
						if(arr[j]==0)
						{
							arr[j]=data;
							printf("\nData Entered");
							break;
						}
						j++;
						if(j>=n)
							j=0;
					}
					if(j==rem)
						printf("\nFull");
				}
				getch();
				break;
			case 2:
				for(i=0;i<n;i++)
					printf("arr[%d]=%d\n",i,arr[i]);
				getch();
				break;
			case 3:
				break;
		}
	}
}
