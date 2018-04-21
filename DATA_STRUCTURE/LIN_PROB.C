#include<stdio.h>

#define b 5

int h(int x)
{
	return(x%b);
}
void linear_prob(int HT[],int x)
{
	int i,j;
	i=h(x);
	j=i;
	while(HT[j]!=x && HT[j]!=0)
	{
		j=(j+1)%b;
		if(j==i)
		{	printf("\nTable Full");
			getch();
			return;
		}
	}
	if(HT[j]==x)
	{
		printf("\nData alreay exists");
		getch();
	}
	else
		HT[j]=x;
}

void print_table(int HT[])
{
	int i;
	clrscr();
	printf("Hash table:");
	for(i=0;i<b;i++)
	{
		printf("\nHT[%d]=%d",i,HT[i]);
	}
}


void main()
{

	int HT[b];
	int i,j,data;
	char ans;
	clrscr();
	for(i=0;i<b;i++)
		HT[i]=0;
	do
	{
		printf("Enter element to insert:");
		scanf("%d",&data);
		linear_prob(HT,data);
		print_table(HT);
		printf("\nDo you insert another[y/n]");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y'||ans=='Y');
}









