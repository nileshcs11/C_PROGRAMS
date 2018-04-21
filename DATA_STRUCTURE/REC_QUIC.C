#include<stdio.h>
#include<conio.h>

void Quick_sort(int A[],int m,int n);


void main()
{
    int *A;
    int i,max,n;
    printf("\nEnter No. of elements:");
    scanf("%d",&n);
    A=(int*)malloc(sizeof(int)*(n+2));
    printf("\nEnter Elements:");
    for(i=1;i<=n;i++)
	scanf("%d",&A[i]);
    max=A[1];
    for(i=2;i<=n;i++)
    {	if(A[i]>max)
	    max=A[i];
    }
    A[n+1]=max;
    Quick_sort(A,1,n);
    printf("\nSorted Elements are:");
    for(i=1;i<=n;i++)
      printf("%d,",A[i]);
    printf("\b  ");
    getch();
}

void Quick_sort(int A[],int m,int n)
{
      int pivot,i,j,t;
      if(m<n)
      {
	    pivot=A[m];
	    i=m;
	    j=n+1;
	    do
	    {
		do
		{
		    i=i+1;
		}while(A[i]<pivot);
		do
		{
		    j=j-1;
		}while(A[j]>pivot);
		if(i<j)
		{
		     t=A[i];
		     A[i]=A[j];
		     A[j]=t;
		}
	    }while(i<j);

	    t=A[j];
	    A[j]=A[m];
	    A[m]=t;

	    Quick_sort(A,m,j-1);
	    Quick_sort(A,j+1,n);
      }

}





























