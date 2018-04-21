#include<stdio.h>

int S[100];
int top=-1;

void push(int d)
{
	if(top==99)
		printf("Overflow");
	else
	{
		top++;
		S[top]=d;
	}
}
int pop()
{
	if(top==-1)
		printf("Underflow");
	else
	{
		top--;
		return(S[top+1]);
	}
}

int all_visit(int status[],int N)
{
       int i;
       for(i=1;i<=N;i++)
       {
		if(status[i]==0)
			return(0);
       }
       return(1);
}

void main()
{
	int N,A[100][100],status[100],i,j,vstar,vstart,found;
	clrscr();
	printf("Enter number of vertices:");
	scanf("%d",&N);
	printf("Enter Adjacency matrix:\n");
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("Enter starting vertex:");
	scanf("%d",&vstart);

	for(i=1;i<=N;i++)
		status[i]=0;
	status[vstart]=1;
	vstar=vstart;

     do
     {
	found=0;
	for(i=1;i<=N;i++)
	{
		if(status[i]==0)
		{
			if(A[vstar][i]==1)
			{
				printf("(%d,%d)",vstar,i);
				status[i]=1;
				push(vstar);
				vstar=i;
				found=1;
				break;
			}
		}
	}
	if(found==0)
		vstar=pop();

      }while(all_visit(status,N)==0);
      getch();
}













