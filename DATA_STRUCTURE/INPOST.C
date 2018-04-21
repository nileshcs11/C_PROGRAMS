#include<stdio.h>
#define N 100

char s[N];
int top=-1;

void push(char e)
{
     if(top==N-1)
	printf("Stack full");
     else
     {
	top++;
	s[top]=e;
     }
}
char pop()
{
	if(top==-1)
		printf("Stack empty");
	else
	{
		top--;
		return(s[top+1]);

	}
}

int ISP(char x)
{
    if(x=='$')
	return(0);
    if(x=='(')
	return(1);
    if(x=='+'||x=='-')
	return(2);
    if(x=='*'||x=='/')
	return(3);
    if(x=='^')
	return(4);
}
int IEP(char x)
{
    if(x=='$')
	return(0);
    if(x=='(')
	return(5);
    if(x=='+'||x=='-')
	return(2);
    if(x=='*'||x=='/')
	return(3);
    if(x=='^')
	return(4);
}

void main()
{

     char E[100],x,y;
     int i;
     printf("\nEnter an infix expression ended by $ :");
     scanf("%s",&E);
     printf("\nEqivalent postfix expression is :");
     push('$');
     i=0;
     x=E[i];

     while(x!='$')
     {
	if((x>='A' && x<='Z')||(x>='a'&& x<='z')||(x>='0'&&x<='9'))
		printf("%c",x);
	else
	{
		if(x==')')
		{
			while((y=pop())!='(')
			    printf("%c",y);
		}
		else//operator
		{
			while(ISP(s[top])>=IEP(x))
			{
			    y=pop();
			    printf("%c  ",y);
			}
			push(x);
		}
	}
	i++;
	x=E[i];
     }
     while(top>=0)
     {
	  y=pop();
	  printf("%c",y);
     }
     getch();
}



















