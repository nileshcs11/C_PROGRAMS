#include<stdio.h>

void radix_sort(int A[],int n);
void main()
{

	int A[100],i,N;
	clrscr();

	printf("Enter number of elements:");
	scanf("%d",&N);

	printf("Enter eleents:");
	for(i=1;i<=N;i++)
		scanf("%d",&A[i]);

	radix_sort(A,N);

	printf("Sorted elements are:");
	for(i=1;i<=N;i++)
		printf("%d  ",A[i]);
	getch();
}
void radix_sort(int A[],int n)
{
	int i,j,k,l,digit,d,max,div,b;
	int buck[10],bucket[10][100];

	max=A[1];
	for(i=2;i<=n;i++)
	{
		if(max<A[i])
			max=A[i];
	}
	d=0;
	while(max!=0)
	{
		max=max/10;
		d++;
	}
	div=1;
	for(digit=1;digit<=d;digit++)
	{
		for(i=0;i<10;i++)
		{
			buck[i]=0;
		}

		for(i=1;i<=n;i++)
		{
		      b=(A[i]/div)%10;
		      bucket[b][buck[b]]=A[i];
		      buck[b]++;
		}
		j=1;
		for(k=0;k<10;k++)
		{
			for(l=0;l<buck[k];l++)
			{
				A[j]=bucket[k][l];
				j++;
			}
		}
		div=div*10;
	}

}






































