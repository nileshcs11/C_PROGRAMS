#include<stdio.h>
#include<process.h>

struct node
{
int data;
struct node *next;
};

struct node* getnode()
{
 struct node *x;
 x=(struct node*)malloc(sizeof(struct node));
 return(x);
}

struct node* create_list()
{
	struct node *l,*x,*d;
	char ans;
	l=getnode();
	d=l;
	do
	{
	       x=getnode();
	       printf("\nEnter data:");
	       scanf("%d",&x->data);
	       d->next=x;
	       d=x;
	       printf("\nDo you want to insert another[y/n]");
	       fflush(stdin);
	       scanf("%c",&ans);

	}while(ans=='y'||ans=='Y');
	d->next=NULL;
	d=l;
	l=l->next;
	free(d);
	return(l);
}

void display(struct node *l)
{
	struct node *x;
	x=l;
	while(x!=NULL)
	{
		printf("%d-->",x->data);
		x=x->next;
	}
	printf("\b\b\b   ");
}

struct node* insert_first(struct node *l)
{
    struct node *x;
    x=getnode();
    printf("\nEnter data:");
    scanf("%d",&x->data);
    x->next=l;
    l=x;
    return(l);
}

struct node* insert_last(struct node *l)
{
   struct node *d,*x;
   x=getnode();
   printf("\nEnter data:");
   scanf("%d",&x->data);
   x->next=NULL;
   if(l==NULL)
   {
	l=x;
   }
   else
   {
	d=l;
	while(d->next!=NULL)
		d=d->next;
	d->next=x;
   }
   return(l);
}

struct node* insert_anypos(struct node *l)
{
struct node *x,*y;
int no_of_nodes,pos,i;

no_of_nodes=1;
x=l;
while(x->next!=NULL)
{
	no_of_nodes++;
	x=x->next;
}
printf("Enter Position:");
scanf("%d",&pos);
if(pos<1||pos>no_of_nodes+1)
	printf("\nErroreous position");
else
{
      y=getnode();
      printf("Enter data:");
      scanf("%d",&y->data);
      if(pos==1)
      {
	y->next=l;
	l=y;
      }
      else
      {
	x=l;
	for(i=1;i<=pos-2;i++)
		x=x->next;
	y->next=x->next;
	x->next=y;
      }
}
return(l);
}

struct node* delete_last(struct node *l)
{
    struct node *x,*d;
    if(l==NULL)
	printf("Empty list");
    else
    {
	if(l->next==NULL)
	{
		x=l;
		l=NULL;
		free(x);
	}
	else
	{
	       x=l;
	       while(x->next!=NULL)
	       {	d=x;
			x=x->next;
	       }
	       d->next=NULL;
	       free(x);
	}
    }
    return(l);
}
int main()
{
  int ans;
  FILE *fp;
  struct node *l;

  fp=fopen("output.txt","w");

  do
  {
	clrscr();

	printf("\nPress 1:Create List");
	printf("\nPress 2: Display");
	printf("\nPress 3: Insert at First");
	printf("\nPress 4: Insert at Last");
	printf("\nPress 5: Insert at any position");
	printf("\nPress 6: Delete from last");
	printf("\nPress 7: Exit");
	printf("\nEnter Your choice:");
        scanf("%d",&ans);
	switch(ans)
	{
		case 1: l=create_list();
			break;
		case 2: display(l);
			break;
		case 3: l=insert_first(l);
			break;
		case 4: l=insert_last(l);
			break;
		case 5: l=insert_anypos(l);
			break;
		case 6: l=delete_last(l);
			break;
		case 7: exit(0);
	}
	getch();
  }while(1);
}
