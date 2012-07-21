/***************************************************************************
		Aim  : Implementation of BFS and DFS.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int check[10];
int queue[10],rear = -1;

int count(int x[],int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	   c=c+x[i];
	if(c==n)
		return 1;
	return 0;
}

void adjmat(int a[][10])
{
    int i,j,e;
    printf("\nWant to enter an edge(0:no;1:yes) : ");
    scanf("%d",&e);

    while(e)
    {
		printf("Enter node number from & to : ");
		scanf("%d%d",&i,&j);
		a[--i][--j] = 1;
		printf("\nWant to enter an edge(0:no;1:yes) : ");
		scanf("%d",&e);
    }
}

void dfs(int a[][10],int n,int v)
{
    int i;
    printf("%d-",v+1);
    check[v] = 1;
    
	for(i=0;i<n;i++)
    {
		if(a[v][i]!=0 && check[i]!=1)
			dfs(a,n,i);
    }
}

void bfs(int a[][10],int n,int v)
{
    int i,j;
    if(!count(check,10))
    {
		for(i=0;i<n;i++)
			if(a[v][i]!=0 && check[i]!=1)
			{
				printf("%d-",i+1);
				check[i]=1;
				queue[++rear]=i;
			}
		j = queue[0];
	
		for(i=0;i<rear;i++)
			queue[i]=queue[i+1];
	
		queue[rear] = 0;
		rear = rear - 1;
		bfs(a,n,j);
    }
}

void main()
{
    int mat[10][10] = {0};
    int i,n,ch,v;
    printf("Enter no of nodes\n");
    scanf("%d",&n);

	adjmat(mat);
    
	while(1)
    {
		printf("\n1: Depth First Search\n");
		printf("2: Breadth First Search\n");
		printf("3: Exit\n");
		printf("Enter your choice ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				for(i=0;i<n;i++)
					check[i]=0;
				printf("Enter starting node : ");
				scanf("%d",&v);
				dfs(mat,n,v-1) ;
				break;

			case 2:
				for(i=0;i<n;i++)
					check[i]=0;
				printf("Enter starting node : ");
				scanf("%d",&v);
				printf("%d-",v);
				check[v-1]=1;
				bfs(mat,n,v-1) ;
				break;
			case 3:
				break;
		}
	}
}

/******************************** OUTPUT **************************************

		Enter no of nodes
		5

		Want to enter an edge(0:no;1:yes) : 1
		Enter node number from & to : 3 2

		Want to enter an edge(0:no;1:yes) : 1
		Enter node number from & to : 3 5

		Want to enter an edge(0:no;1:yes) : 1
		Enter node number from & to : 3 4

		Want to enter an edge(0:no;1:yes) : 1
		Enter node number from & to : 5 4

		Want to enter an edge(0:no;1:yes) : 1
		Enter node number from & to : 4 5

		Want to enter an edge(0:no;1:yes) : 1
		Enter node number from & to : 1 3

		Want to enter an edge(0:no;1:yes) : 1
		Enter node number from & to : 1 4

		Want to enter an edge(0:no;1:yes) : 0

		1: Depth First Search
		2: Breadth First Search
		3: Exit
		Enter your choice: 1
		Enter starting node : 1
		1-3-2-4-5

		Enter your choice: 2
		Enter starting node : 1
		1-3-4-2-5

******************************************************************************/