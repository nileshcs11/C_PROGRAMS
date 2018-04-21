#include<stdio.h>
#include<conio.h>


void merge_sort(int A[],int m,int n);
void merging(int A[],int m,int p,int n);

int *B;

void main()
{
    int *A;
    int i,max,n;
    clrscr();
    printf("\nEnter No. of elements:");
    scanf("%d",&n);
    A=(int*)malloc(sizeof(int)*(n+1));
    B=(int*)malloc(sizeof(int)*(n+1));

    printf("\nEnter Elements:");
    for(i=1;i<=n;i++)
	scanf("%d",&A[i]);
    merge_sort(A,1,n);
    printf("\nSorted Elements are:");
    for(i=1;i<=n;i++)
      printf("%d,",A[i]);
    printf("\b  ");
    getch();
}

void merge_sort(int A[],int m,int n)
{
   int p;
   if(m<n)
   {
      p=(m+n)/2;
      merge_sort(A,m,p);
      merge_sort(A,p+1,n);
      merging(A,m,p,n);
   }
}

void merging(int A[],int m,int p,int n)
{

      int i,j,k,l;

      i=m;
      j=p+1;
      k=m;

      while(i<=p && j<=n)
      {
	    if(A[i]<A[j])
	    {
		B[k]=A[i];
		i=i+1;
	    }
	    else
	    {
		B[k]=A[j];
		j=j+1;
	    }
	    k=k+1;
      }

      while(i<=p)
      {
	  B[k]=A[i];
	  i=i+1;
	  k=k+1;
      }
      while(j<=n)
      {
	  B[k]=A[j];
	  j=j+1;
	  k=k+1;
      }

      for(l=m;l<=n;l++)
	A[l]=B[l];
}































