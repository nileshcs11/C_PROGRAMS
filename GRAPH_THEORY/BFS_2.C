#include<stdio.h>
#define size 100

int Q[size];
int front=-1;
int rear=-1;

void ENQUE(int x);



void main()
{
	int N,A[size][size],status[size],u,v,vstart;

	clrscr();
	printf("Enter number of vertices:");
	scanf("%d",&N);
	printf("Enter Adjacency matrix:");
	for(u=1;u<=N;u++)
	{
		for(v=1;v<=N;v++)
		{
		   scanf("%d",&A[u][v]);
		}
	}
	printf("Enter starting vertex:");
	scanf("%d",&vstart);

	for(v=1;v<=N;v++)
	    status[v]=0;
	status[vstart]=1;

	ENQUE(vstart);
	printf("Selected edges are:\n");
	while(front!=rear)
	{
		u=DELQUE();
		for(v=1;v<=N;v++)
		{
			if(status[v]==0)
			{
				if(A[u][v]==1)
				{
					printf("(%d,%d)\n",u,v);
					status[v]=1;
					ENQUE(v);
				}
			}
		}
		status[u]=2;
	}
	getch();
}





void ENQUE(int x)
{
	if(rear==size-1)
		printf("Queue full");
	else
	{
		rear++;
		Q[rear]=x;
	}
}
int DELQUE()
{
	if(front==rear)
		printf("Queue empty");
	else
	{
		front++;
		return(Q[front]);
	}
}

















