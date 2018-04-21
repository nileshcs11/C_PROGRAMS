#include<stdio.h>

#define N 10

struct node
{
	int data;
	struct node *next;
};

struct node* getnode()
{
	struct node *x;
	x=(struct node*)malloc(sizeof(struct node));
	x->next=NULL;
	return(x);
}

int h(int x)
{
	return(x%N);
}

void insert(struct node *HT[],int x)
{
	int i;
	struct node *j,*y;
	i=h(x);
	j=HT[i];
	while(j!=NULL)
	{
		if(j->data==x)
		{
			printf("\nAlready Exists");
			return;
		}
		j=j->next;
	}
	y=getnode();
	y->data=x;
	y->next=HT[i];
	HT[i]=y;
}


int main()
{
	int i,data,ans;
	struct node *HT[N],*j;

	for(i=0;i<N;i++)
		HT[i]=NULL;


	while(1)
	{
		clrscr();
		printf("Press 1:Insert element");
		printf("\nPress 2:Display Table");
		printf("\nPress 3:Exit");
		printf("\nEnter your option:");
		scanf("%d",&ans);
		switch(ans)
		{
			case 1: printf("\nEnter Element:");
				scanf("%d",&data);
				insert(HT,data);
				break;
			case 2: printf("The Hash table is:\n");
				for(i=0;i<N;i++)
				{
					printf("HT[%d]-->",i);
					j=HT[i];
					while(j!=NULL)
					{
						printf("%d-->",j->data);
						j=j->next;
					}
					printf("\b\b\b   \n");
				}
				break;
			case 3: exit(0);
		}
		getch();
	}
}
