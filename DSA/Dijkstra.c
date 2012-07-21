/***************************************************************************
	Aim  : Implementation of Shortest Path / Dijkstra's Algorithm.
****************************************************************************/

	#include<stdio.h>
	#include<conio.h>
	#include<stdlib.h>

	int all(int x[],int v)
	{
		int i;
		for(i=1;i<=v;i++)
			if(x[i]==0)
				return 0;
		
		return 1;
	}

	void adjmat(int a[][10])
	{
		int i,j,e,w;
		printf("\nEnter an Edge ?(0:no/1:yes) : ");
		scanf("%d",&e);

		while(e)
		{
			printf("\nEnter node number from & to :");
			scanf("%d%d",&i,&j);
			printf("\nEnter Weight of Edge : ");
			scanf("%d",&w);
			a[i][j] = w;
			a[j][i] = w;
			printf("Enter an Edge ?(0:no/1:yes) : ");
			scanf("%d",&e);
		}
	}

	void dijkstra(int a[][10],int v)
	{
		int d[10],p[10]={0},visit[10]={0};
		int s,dest,curr,dc,i,x,l,min;
		char ch = 'y';
		
		for(i=0;i<10;i++)
			d[i] = 32767;

		printf("\nEnter source & destination node : ");
		scanf("%d %d",&s,&dest);
		
		curr = s;
		d[s] = 0;
		visit[s] = 1;
		dc = d[curr];
		
		while(!all(visit,v))
		{
			for(i=1;i<=v;i++)
			{
				if(a[curr][i]!=0)
					if(visit[i]==0)
						if(d[i]>a[curr][i]+dc)
						{
							d[i]=a[curr][i]+dc;
							p[i]=curr;
						}
			}
			
			min = 32767;
		   
			for(i=1;i<=v;i++)
			{
				if(visit[i]==0)
					if(d[i]<min)
					{
						min = d[i];
						curr = i;
					}
			}
		   
			dc = d[curr];
		   visit[curr] = 1;
		}
		
			printf("\nShortest Distance from %d to %d : ",s,dest);
			printf("%d\n",d[dest]);
			printf("Path = \n");
			l = dest;

			do
			{
				x = p[l];
				printf("\nVertex %d connected to %d\n",l,x);
				l = x;
			}while(l!=s && s!=dest);
	}

	void main()
	{
		int mat[10][10]={0};
		int n = 0;
		system("cls");
    
		printf("Enter Total No. of Nodes : ");
		scanf("%d",&n);
    
		adjmat(mat);
		dijkstra(mat,n);
	}


/******************************** OUTPUT **************************************

		Enter Total No. of Nodes : 4

		Enter an Edge ?(0:no/1:yes) : 1

		Enter node number from & to :1 2

		Enter Weight of Edge : 10
		Enter an Edge ?(0:no/1:yes) : 1

		Enter node number from & to :2 3

		Enter Weight of Edge : 20
		Enter an Edge ?(0:no/1:yes) : 1

		Enter node number from & to :1 3

		Enter Weight of Edge : 40
		Enter an Edge ?(0:no/1:yes) : 1

		Enter node number from & to :1 4

		Enter Weight of Edge : 5
		Enter an Edge ?(0:no/1:yes) : 1

		Enter node number from & to :4 3

		Enter Weight of Edge : 3
		Enter an Edge ?(0:no/1:yes) : 0

		Enter source & destination node : 1 3

		Shortest Distance from 1 to 3 : 8
		Path =

		Vertex 3 connected to 4

		Vertex 4 connected to 1

******************************************************************************/