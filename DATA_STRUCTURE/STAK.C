#include<stdio.h>
#define N 5

int s[N];
int top=-1;

void push(int e)
{
    if(top==N-1)
	printf("\nStack overflow");
    else
    {
	top++;
	s[top]=e;
    }
}
int pop(void)
{
	int d;
	if(top==-1)
		printf("\nStack underflow");
	else
	{
		d=s[top];
		top--;
		return(d);
	}
}

void display()
{
	int i;
	if(top==-1)
		printf("\nStack Empty");
	else
	{
		for(i=0;i<=top;i++)
			printf("%d, ",s[i]);
		printf("\b\b  ");
	}
}

int main()
{
  int ans,d;

  do
  {
	clrscr();
	printf("\nPress 1: PUSH");
	printf("\nPress 2: POP");
	printf("\nPress 3: DISPLAY");
	printf("\nPress 4: EXIT");
	printf("\nEnter option:");
	scanf("%d",&ans);
	switch(ans)
	{
		case 1: printf("\nEnter data:");
			scanf("%d",&d);
			push(d);
			break;
		case 2: if(top!=-1)
			{	d=pop();
				printf("Deleted element:%d",d);
			}
			else
				printf("Stack Empty");
			break;
		case 3: display();
			break;
		case 4: return(0);
	}
	getch();
  }while(1);
}

































