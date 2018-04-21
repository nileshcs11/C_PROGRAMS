#include<stdio.h>
#define N 100

void merge_sort(int A[],int n);
void merging(int A[],int m,int p, int n);

int start[N],stop[N],beg[N],mid[N],end[N];

int top1=-1;
int top2=-1;
int top3=-1;
int top4=-1;
int top5=-1;

void push(int s[],int *top,int data)
{
	if((*top)==N-1)
		printf("Overflow");
	else
	{
		(*top)++;
		s[*top]=data;
	}
}

int pop(int s[],int *top)
{
	if((*top)==-1)
		printf("Underflow");
	else
	{
		(*top)--;
		return(s[(*top)+1]);
	}
}
void main()
{
	int A[N],max,i,n;
	clrscr();
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	merge_sort(A,n);
	printf("Sorted Array is:");
	for(i=1;i<=n;i++)
		printf("%d  ",A[i]);
	getch();
}

void merge_sort(int A[],int n)
{
	int m,p;
	push(start,&top1,1);
	push(stop,&top2,n);
	while(top1!=-1 && top2!=-1)
	{
		m=pop(start,&top1);
		n=pop(stop,&top2);
		p=(m+n)/2;
		push(beg,&top3,m);
		push(mid,&top4,p);
		push(end,&top5,n);
		if(m<p)
		{
			push(start,&top1,m);
			push(stop,&top2,p);
		}
		if(p+1<n)
		{
			push(start,&top1,p+1);
			push(stop,&top2,n);
		}
	}
	while(top3!=-1)
	{
		m=pop(beg,&top3);
		p=pop(mid,&top4);
		n=pop(end,&top5);
		merging(A,m,p,n);
	}
}

void merging(int A[],int m,int p, int n)
{
	int i,j,k;
	int *B;
	B=(int*)malloc(N*sizeof(int));
	i=m;
	j=p+1;
	k=m;
	while(i<=p&&j<=n)
	{
		if(A[i]<A[j])
		{
			B[k]=A[i];
			i++;
		}
		else
		{
			B[k]=A[j];
			j++;
		}
		k++;
	}
	while(i<=p)
	{
		B[k]=A[i];
		k++;
		i++;
	}
	while(j<=n)
	{
		B[k]=A[j];
		k++;
		j++;
	}
	for(i=m;i<=n;i++)
	{
		A[i]=B[i];
	}
}






























