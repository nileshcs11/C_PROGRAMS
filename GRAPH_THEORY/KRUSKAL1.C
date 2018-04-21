#include<stdio.h>

int parent[100];

int root(int v)
{
	while(parent[v]!=0)
		v=parent[v];
	return(v);
}



void main()
{
	int N,L[100][100],i,j,a,b,u,v,ne,min,cost;

	printf("Enter number of vertices:");
	scanf("%d",&N);
	printf("Enter Length matrix:\n");
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&L[i][j]);
		}
	}

	for(i=1;i<=N;i++)
		parent[i]=0;

	ne=0;
	cost=0;
	while(ne!=N-1)
	{
		min=9999;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(i!=j)
				{
					if(L[i][j]<min)
					{
						min=L[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		a=root(u);
		b=root(v);
		if(a!=b)
		{
			ne++;
			printf("(%d,%d)",u,v);
			parent[b]=a;
			cost=cost+L[u][v];
		}
		L[u][v]=9999;
		L[v][u]=9999;
	}
	printf("Cost of MST=%d",cost);
	getch();
}


























