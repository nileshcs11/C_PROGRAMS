#include<stdio.h>
#define N 100



void adjust(int A[],int i,int n)
{
	int j,t;
	j=2*i;

	if(j<=n)
	{
		if(j<n)
		{
			if(A[j]<A[j+1])
				j=j+1;
		}
		if(A[j]<=A[i])
		{
			return;
		}
		t=A[j];
		A[j]=A[i];
		A[i]=t;
		adjust(A,j,n);
	}
}

void heap_sort(int A[],int n)
{
	int i,t;
	for(i=n/2;i>=1;i--)
		adjust(A,i,n);
	for(i=n;i>=2;i--)
	{
		t=A[1];
		A[1]=A[i];
		A[i]=t;
		adjust(A,1,i-1);
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
	heap_sort(A,n);
	printf("Sorted Array is:");
	for(i=1;i<=n;i++)
		printf("%d  ",A[i]);
	getch();
}


















