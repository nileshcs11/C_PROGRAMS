#include<stdio.h>

struct node
{
	int coeff;
	int exp;
	struct node *next;
};

struct node* getnode()
{
	struct node *x;
	x=(struct node*)malloc(sizeof(struct node));
	return(x);
}

struct node* create()
{
	struct node *x,*y,*z;
	char ans;
	x=getnode();
	y=x;
	do
	{

		z=getnode();
		printf("\nEnter Coefficient:");
		scanf("%d",&z->coeff);
		printf("\nEnter Exponent:");
		scanf("%d",&z->exp);
		y->next=z;
		y=z;
		printf("\nWant to insert another[Y/N]");
		fflush(stdin);
		scanf("%c",&ans);
	  }while(ans=='y'||ans=='Y');
	  y->next=NULL;
	  y=x;
	  x=x->next;
	  free(y);
	  return(x);
}
void display(struct node *p)
{
	printf("%dX^%d",p->coeff,p->exp);
	p=p->next;
	while(p!=NULL)
	{
		if(p->coeff<0)
			printf("%dX^%d",p->coeff,p->exp);
		else
			printf("+%dX^%d",p->coeff,p->exp);
		p=p->next;
	}

}
struct node* attach(struct node *c,int coeff,int exp)
{
	struct node *x;
	x=getnode();
	x->coeff=coeff;
	x->exp=exp;
	c->next=x;
	c=x;
	return(c);
}

struct node* add(struct node *p1,struct node *p2)
{
      struct node *a,*b,*c,*p3;
      int data;
      a=p1;
      b=p2;
      p3=getnode();
      c=p3;

      while(a!=NULL && b!=NULL)
      {
		if(a->exp==b->exp)
		{
			data=a->coeff+b->coeff;
			if(data!=0)
			       c=attach(c,data,a->exp);
			a=a->next;
			b=b->next;
		}
		else
		{
			if(a->exp<b->exp)
			{
				c=attach(c,b->coeff,b->exp);
				b=b->next;
			}
			else
			{
				c=attach(c,a->coeff,a->exp);
				a=a->next;
			}
		}
      }
      while(a!=NULL)
      {
		c=attach(c,a->coeff,a->exp);
		a=a->next;
      }
      while(b!=NULL)
      {
		c=attach(c,b->coeff,b->exp);
		b=b->next;
      }
      c->next=NULL;
      c=p3;
      p3=p3->next;
      free(c);
      return(p3);
}

struct node* mult(struct node* p1,struct node *p2)
{
	struct node *s,*p3,*c,*a;
	int coeff,exp;
	s=NULL;
	while(p1!=NULL)
	{

		p3=getnode();
		c=p3;
		a=p2;
		while(a!=NULL)
		{
			coeff=p1->coeff*a->coeff;
			exp=p1->exp+a->exp;
			c=attach(c,coeff,exp);
			a=a->next;
		}
		c->next=NULL;
		c=p3;
		p3=p3->next;
		free(c);
		s=add(s,p3);
		p1=p1->next;
	}
	return(s);
}


void main()
{
	struct node *p1,*p2,*p;
	int ans;

	while(1)
	{
		clrscr();
		printf("\nPress 1: Polynomial Addition");
		printf("\nPress 2: Polynomial Subtraction");
		printf("\nPress 3: Polynomial Multiplication");
		printf("\nPress 4: Exit");
		printf("\nEnter option:");
		scanf("%d",&ans);
		switch(ans)
		{
			case 1: printf("\nEnter 1st Polynomial");
				p1=create();

				printf("\nEnter 2nd Polynomial");
				p2=create();
				printf("\nFirst Polynomial:");
				display(p1);
				printf("\nSecond Polynomial:");
				display(p2);
				printf("\nThe result:");
				p=add(p1,p2);
				display(p);
				break;
		     /* case 2:   p1=create();
				p2=create();
				p=sub(p1,p2);
				display(p);
				break; */
			case 3: p1=create();
				p2=create();
				p=mult(p1,p2);
				display(p);
				break;
			case 4: return;
		}
		getch();
	}
}
