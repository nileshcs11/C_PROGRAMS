#include<stdio.h>

struct tnode
{
	struct tnode *lchild;
	int data;
	struct tnode *rchild;
};

struct tnode* getnode()
{
	struct tnode *t;
	t=(struct tnode*)malloc(sizeof(struct tnode));
	return(t);
}

struct tnode* insert_bst(struct tnode *root,int x)
{
	struct tnode *p,*t,*y;
	int found=0;
	t=root;

	while(t!=NULL && found==0)
	{
		if(t->data==x)
			found=1;
		else
		{
			p=t;
			if(t->data>x)
				t=t->lchild;
			else
				t=t->rchild;
		}
	}
	if(found==0)
	{
	     y=getnode();
	     y->data=x;
	     y->lchild=NULL;
	     y->rchild=NULL;
	     if(root==NULL)
		root=y;
	     else
	     {
		if(p->data>x)
			p->lchild=y;
		else
			p->rchild=y;
	     }
	}
	else
		printf("Data already exists");
	return(root);
}

void inorder(struct tnode *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
	}

}

struct tnode* INSUC(struct tnode* t)
{
	struct tnode *x;
	x=t->rchild;
	while(x->lchild!=NULL)
	{
		x=x->lchild;
	}
	return(x);
}

struct node* delete_bst(struct tnode *root,int x)
{
	struct tnode *t,*prev,*p;
	int found=0,data,option;
	t=root;
	while(t!=NULL && found==0)
	{
	       if(t->data==x)
			found=1;
		else
		{
			prev=t;
			if(t->data>x)
			     t=t->lchild;
			else
			     t=t->rchild;
		}
	}
	if(found==0)
	{
	    printf("NOt foud");
	}
	else
	{     	if(t==root)
		{
		     if(root->lchild==NULL && t->rchild==NULL)
				root=NULL;
		     if(root->lchild!=NULL && root->rchild==NULL)
				root=root->lchild;

		     if(root->lchild==NULL && root->rchild!=NULL)
				root=root->rchild;
		     if(root->lchild!=NULL && root->rchild!=NULL)
		     {
				p=INSUC(t);
				data=p->data;
				delete_bst(root,data);
				t->data=data;
		     }

		}
		else
		{
			if(t->lchild==NULL && t->rchild==NULL)
				option=1;

			else
			{	if(t->lchild!=NULL && t->rchild!=NULL)
					option=3;
				else
					option=2;
			}
			if(option==1)
			{
				if(prev->lchild==t)
					prev->lchild=NULL;
				else
					prev->rchild=NULL;
			}

			if(option==2)
			{
				if(t->lchild!=NULL)
				{
					if(prev->lchild==t)
						prev->lchild=t->lchild;
					else
						prev->rchild=t->lchild;
				}

				if(t->rchild!=NULL)
				{
					if(prev->lchild==t)
						prev->lchild=t->rchild;
					else
						prev->rchild=t->rchild;
				}
			  }
			  if(option==3)
			  {
				p=INSUC(t);
				data=p->data;
				root=delete_bst(root,data);
				t->data=data;
			  }
		}
	}
	return(root);
}

void main()
{
	struct tnode *root;
	int i,n,data;
	char ans;
	root=NULL;

	printf("ENter number of data to be inserted:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("Enter data");
		scanf("%d",&data);
		root=insert_bst(root,data);
	}
	printf("Inorder sequence is:");
	if(root==NULL)
		printf("tree empty");
	else
		inorder(root);
	do
	{
		printf("Enter data to be deleted:");
		scanf("%d",&data);
		root=delete_bst(root,data);
		if(root==NULL)
			printf("tree empty");
		else
			inorder(root);
		printf("Want to delete another[y/n]");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
	getch();
}









