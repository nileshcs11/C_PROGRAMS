#include<stdio.h>
#include<conio.h>

#define N 5

void display();
void insert(int data);

int Q[N];
int front=-1;
int rear=-1;


void main()
{
    int ans,data;
    while(1)
    {
       clrscr();
       printf("\nPress 1: Insert");
       printf("\nPress 2: Delete");
       printf("\nPress 3: Display");
       printf("\nPress 4: Exit");
       printf("\nEnter your choice:");
       scanf("%d",&ans);
       switch(ans)
       {
	   case 1: printf("\nEnter data:");
		   scanf("%d",&data);
		   insert(data);
		   break;
	   case 2: data=delette();
		   printf("\nDeleted element is:%d",data);
		   break;
	   case 3: display();
		   break;
	   case 4: exit(0);

       }
       getch();
    }
}

void insert(int data)
{
   if(rear==N-1)
   {
	  printf("\nQueue full");
   }
   else
   {
	  rear=rear+1;
	  Q[rear]=data;
   }
}

int delette()
{
   if(front==rear)
   {
	printf("\nQueue empty");
   }
   else
   {
	front=front+1;
	return(Q[front]);
   }
}
void display()
{
   int i;
   printf("\nfront<---");
   for(i=front+1;i<=rear;i++)
   {
       printf("%d,",Q[i]);
   }
   printf("\b <---rear");
}











































