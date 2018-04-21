#include<stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct node* getnode()
{
struct node *x;
x=(struct node*)malloc(sizeof(struct node));
return(x);
}

struct node* combine(struct node *p0,struct node *p1)
{
struct node *x,*y,*z;
x=getnode();
y=x;
while(p0->next!=NULL)
{
	z=getnode();
	z->data=p0->data;
	y->next=z;
	y=z;
	p0=p0->next;
}
while(p1!=NULL)
{
	z=getnode();
	z->data=p1->data;
	y->next=z;
	y=z;
	p1=p1->next;
}
y->next=NULL;
y=x;
x=x->next;
free(y);
return(x);
}







void main()
{
	int A[100][100],B[100][100],i,j,k,N;
	struct node *path[100][100],*p0,*p1,*p,*x;

	clrscr();
	printf("\nEnter number of nodes:");
	scanf("%d",&N);

	printf("Enter Length matrix:\n");
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		    scanf("%d",&A[i][j]);
	for(i=1;i<=N;i++)
	{	for(j=1;j<=N;j++)
		{
			if(A[i][j]==0||A[i][j]==9999)
				path[i][j]=NULL;
			else
			{
				path[i][j]=getnode();
				path[i][j]->data=i;
				x=getnode();
				x->data=j;
				x->next=NULL;
				path[i][j]->next=x;
			}
		}
	}


	for(k=1;k<=N;k++)
	{
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(A[i][k]==1 && A[k][j]==1)
				{
					B[i][j]=1;
					if(A[i][j]!=B[i][j])
					{
						p0=path[i][k];
						p1=path[k][j];
						p=combine(p0,p1);
						path[i][j]=p;
					}
				}
				else
					B[i][j]=A[i][j];
			}
		}
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				A[i][j]=B[i][j];
		printf("After %d-th iteration\n",k);
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				printf("%d\t",B[i][j]);
			}
			printf("\n");
		}
		printf("Path matrix\n");
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				p=path[i][j];
				if(p==NULL)
					printf("-\t\t");
				else
				{
					while(p!=NULL)
					{
						printf("%d->",p->data);
						p=p->next;
					}
					 printf("\b\b  \t\t");
				}
			  }
			  printf("\n");
		}
		getch();

	}
	getch();
}
