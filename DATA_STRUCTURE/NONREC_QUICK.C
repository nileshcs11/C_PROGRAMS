#include<stdio.h>
#include<conio.h>

void Quick_sort(int A[],int m,int n);


int start[100],stop[100];
int top1=-1;
int top2=-1;

void push(int s[],int *top,int x)
{
	if(*top==99)
	{
		 printf("Stackfull");
	}
	else
	{
		(*top)++;
		s[*top]=x;
	}
}

int pop(int s[],int *top)
{
       if(*top==-1)
       {
		printf("Stack empty");
       }
       else
       {
		(*top)--;
		return(s[(*top)+1]);
       }
}
void main()
{
    int *A;
    int i,max,n;
    clrscr();
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

void Quick_sort(int A[],int m, int n)
{
    int j;
    push(start,&top1,m);
    printf("top1=%d",top1);
    push(stop,&top2,n);
    printf("top2=%d",top2);

    while( top1!=-1 && top2!=-1)
    {
      m=pop(start,&top1);
      n=pop(stop,&top2);
      j=partition(A,m,n);

      if(m<j-1)
      {
	   push(start,&top1,m);
	   push(stop,&top2,j-1);
      }
      if(j+1<n)
      {
	   push(start,&top1,j+1);
	   push(stop,&top2,n);
      }
    }
}

int partition(int A[],int m,int n)
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
	    return(j);

      }

}
