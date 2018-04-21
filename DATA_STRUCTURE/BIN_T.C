#include<stdio.h>
#define N 20
struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct node *S[N];
int top=-1;

struct node *Q[N];
int f=-1;
int r=-1;

void enque(struct node *e)
{
	if(r==N-1)
		printf("Queue Full");
	else
	{
		r++;
		Q[r]=e;
	}
}

struct node* delque()
{
	if(f==r)
		printf("Queue Empty");
	else
	{
		f++;
		return(Q[f]);
	}
}

void push(struct node *e)
{
	if(top==N-1)
		printf("Stack Full");
	else
	{
		top++;
		S[top]=e;
	}
}

struct node* pop()
{
	if(top==-1)
		printf("Stack Empty");
	else
	{
		top--;
		return(S[top+1]);
	}
}






struct node* getnode()
{
	struct node *x;
	x=(struct node *)malloc(sizeof(struct node));
	x->lchild=NULL;
	x->rchild=NULL;
	return(x);
}
void rec_inorder(struct node *t)
{
	if(t!=NULL)
	{
		rec_inorder(t->lchild);
		printf("%d ",t->data);
		rec_inorder(t->rchild);
	}
}

void nonrec_inorder(struct node *t)
{
    do
    {
	while(t!=NULL)
	{
		push(t);
		t=t->lchild;
	}
	t=pop();
	printf("%d ",t->data);
	t=t->rchild;
    }while(top!=-1 || t!=NULL);
}

void create(struct node *x)
{
	struct node *p;
	char ans;
	printf("Do you want to create left child of %d? [Y/N]",x->data);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y'||ans=='y')
	{
		p=getnode();
		printf("\nEnter data:");
		scanf("%d",&p->data);
		x->lchild=p;
		create(p);
	}
	else
		x->lchild=NULL;
	printf("Do you want to create right child of %d? [Y/N]",x->data);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y'||ans=='y')
	{
		p=getnode();
		printf("\nEnter data:");
		scanf("%d",&p->data);
		x->rchild=p;
		create(p);
	}
	else
		x->rchild=NULL;
}

int count_leaf(struct node *t)
{
	if(t==NULL)
		return(0);
	if(t->lchild==NULL && t->rchild==NULL)
		return(1);
	else
		return(count_leaf(t->lchild)+count_leaf(t->rchild));
}

int height(struct node *t)
{
	int hl,hr;
	if(t==NULL)
		return(0);
	else
	{
		hl=height(t->lchild);
		hr=height(t->rchild);
		if(hl>hr)
			return(hl+1);
		else
			return(hr+1);
	}
}

void level_traverse(struct node *t)
{
	if(t==NULL)
		printf("Tree is empty");
	else
	{
		enque(t);
		do
		{
			t=delque();
			printf("%d ",t->data);
			if(t->lchild!=NULL)
				enque(t->lchild);
			if(t->rchild!=NULL)
				enque(t->rchild);
		}while(f!=r);
	}
}
void mirror_image(struct node *t)
{
	struct node *temp;
	if(t!=NULL)
	{
		temp=t->rchild;
		t->rchild=t->lchild;
		t->lchild=temp;
		mirror_image(t->lchild);
		mirror_image(t->rchild);
	}
}

int main()
{
	int ans,n;
	struct node *t,*x;

	while(1)
	{
		printf("\nPress 1: Create");
		printf("\nPress 2: Recursive Inorder traversal");
		printf("\nPress 3: Non Recursive inorder traversal");
		printf("\nPress 4: Count leaf node");
		printf("\nPress 5: Find Height");
		printf("\nPress 6: Level-wise traversal");
		printf("\nPress 7: Mirror Image");
		printf("\nPress 8: exit");
		printf("\nEnter option:");
		scanf("%d",&ans);
		switch(ans)
		{
		     case 1: t=getnode();
			     printf("Enter root data");
			     scanf("%d",&t->data);
			     x=t;
			     create(x);
			     break;
		     case 2: rec_inorder(t);
			     break;
		     case 3: nonrec_inorder(t);
			     break;
		     case 4: n=count_leaf(t);
			     printf("No. of leaves is: %d",n);
			     break;
		     case 5: n=height(t);
			     printf("Height of tree is: %d",n);
			     break;
		     case 6: level_traverse(t);
			     break;
		     case 7: printf("\tGiven tree:");
			     rec_inorder(t);
			     mirror_image(t);
			     printf("Mirror image of the tree:");
			     rec_inorder(t);
			     break;
		     case 8: return(0);
		}
	}

}




