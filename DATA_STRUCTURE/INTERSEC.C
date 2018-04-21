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

void main()
{
    struct node *l1,*l2,*l3,*a,*b,*c,*x;
    int found;
    clrscr();
    printf("Enter First list");
    l1=create_list();
    printf("Enter Second list");
    l2=create_list();
    printf("\n1st list:");
    display(l1);
    printf("\n2nd list:");
    display(l2);

    l3=getnode();
    a=l1;
    c=l3;
    while(a!=NULL)
    {
	b=l2;
	found=0;
	while(b!=NULL)
	{
		if(a->data==b->data)
		{
			found=1;
			break;
		}
		b=b->next;
	}
	if(found==1)
	{
		x=getnode();
		x->data=a->data;
		c->next=x;
		c=x;
	}
	a=a->next;
    }
    c->next=NULL;
    c=l3;
    l3=l3->next;
    free(c);
    printf("\nIntersection of these lists is:");
    display(l3);
    getch();
}


