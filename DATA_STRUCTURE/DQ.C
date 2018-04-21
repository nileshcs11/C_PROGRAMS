#include<stdio.h>
#include<conio.h>

#define N 5

void display();
void insert_rear(int data);
void insert_front(int data);

int Q[N];
int front=-1;
int rear=-1;


void main()
{
    int ans,data;
    while(1)
    {
       clrscr();
       printf("\nPress 1: Insert front");
       printf("\nPress 2: Delete front");
       printf("\nPress 3: Insert rear");
       printf("\nPress 4: Delete rear");
       printf("\nPress 5: Display");
       printf("\nPress 6: Exit");
       printf("\nEnter your choice:");
       scanf("%d",&ans);
       switch(ans)
       {
	   case 1: printf("\nEnter data:");
		   scanf("%d",&data);
		   insert_front(data);
		   break;
	   case 2: data=delette_front();
		   printf("\nDeleted element is:%d",data);
		   break;
	   case 3: printf("\nEnter data:");
		   scanf("%d",&data);
		   insert_rear(data);
		   break;
	   case 4: data=delette_rear();
		   printf("\nDeleted element is:%d",data);
		   break;
	   case 5: display();
		   break;
	   case 6: exit(0);

       }
       getch();
    }
}

void insert_rear(int data)
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

int delette_front()
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
void insert_front(int data)
{
    if(front==-1)
    {
	 printf("\nQueue full");
    }
    else
    {
	 Q[front]=data;
	 front=front-1;
    }
}
int delette_rear()
{
    if(front==rear)
    {
	printf("\nQueue empty");
    }
    else
    {
	rear=rear-1;
	return(Q[rear+1]);
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
