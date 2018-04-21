#include<stdio.h>
#define INF 9999


void main()
{
int N,L[100][100],status[100],u,v,ne,min,a,b,mincost;

clrscr();
printf("Enter number of vertices:");
scanf("%d",&N);

printf("Enter length matrix:\n");
for(u=1;u<=N;u++)
{
	for(v=1;v<=N;v++)
	{
		scanf("%d",&L[u][v]);
	}
}

for(u=1;u<=N;u++)
{
    for(v=1;v<=N;v++)
    {
	if(L[u][v]==0)
		L[u][v]=INF;
    }
}

for(v=1;v<=N;v++)
	status[v]=0;
status[1]=1;
ne=0;
mincost=0;
printf("Selected edges are:\n");
while(ne!=N-1)
{
	min=INF;
	for(u=1;u<=N;u++)
	{
		if(status[u]==1)
		{
			for(v=1;v<=N;v++)
			{
				if(status[v]==0)
				{
					if(L[u][v]<min)
					{
						min=L[u][v];
						a=u;
						b=v;
					}
				}
			}
		}
	}
	printf("(%d,%d)\n",a,b);
	status[b]=1;
	L[a][b]=INF;
	L[b][a]=INF;
	ne++;
	mincost=mincost+min;
}
printf("Minimum cost of MST=%d",mincost);
getch();
}


































