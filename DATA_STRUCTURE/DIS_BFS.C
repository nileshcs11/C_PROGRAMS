# include <stdio.h>
# define N 30
int queue[N];
int front=-1, rear=-1;
int n;

void enque(int v)
{
	if (rear == N-1)
	{
		printf("Queue is full");
		return;
	}
	rear++;
	queue[rear] = v;
}

int delque()
{
	if(front == rear)
	{
		printf("Queue is empty");
		return (NULL);
	}
	front++;
	return (queue[front]);
}

int not_visited(int stat[])
{
	int i;
	for (i=1;i<=n;i++)
	{
		if(stat[i]==0)
			return(i);
	}
	return 0;
}

int main ()
{
	int i, j, adj[N][N], stat[N], vs, d, comp = 0;
	printf("Enter the number of nodes :");
	scanf("%d", &n);
	printf("Enter the adjacency matrix :\n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &adj[i][j]);
	for (i=1; i<=n; i++)
		stat[i]=0;




	while (vs = not_visited(stat))
	{
		enque(vs);
		stat[vs]=1;

		do
		{
			d = delque();
			for (i=1; i<=n ; i++)
			{
				if(adj[d][i]==1 && stat[i]==0)
				{
					printf("(%d,%d)\n", d, i);
					enque(i);
					stat[i]=1;
				}
			}
			stat[d]=2;
		}while (front != rear);
		comp++;
	}
	printf("The graph has %d components", comp);
	getch();
	return 0;
}
