#include<stdio.h>

void adjust(int A[],int i,int n);
void heap_sort(int A[],int n);

void main()
{

     int A[50], N,i;

     clrscr();
     printf("Enter number of elements:");
     scanf("%d",&N);
     printf("Enter elements:\n");
     for(i=1;i<=N;i++)
	scanf("%d",&A[i]);

     heap_sort(A,N);

     printf("Sorted array is:");
     for(i=1;i<=N;i++)
	printf("%d  ",A[i]);
     getch();
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

void adjust(int A[],int i,int n)
{
    int k,j;
    k=A[i];
    j=2*i;
    while(j<=n)
    {
	if(j<n)
	{
		if(A[j]<A[j+1])
			j=j+1;
	}
	if(k>=A[j])
	{
		A[j/2]=k;
		return;
	}
	A[j/2]=A[j];
	j=2*j;
     }
     A[j/2]=k;
}
























