#include<stdio.h>
#define N 100

int s[N];
int top=-1;

void push(int e)
{
     if(top==N-1)
	printf("Stack full");
     else
     {
	top++;
	s[top]=e;
     }
}
int pop()
{
	if(top==-1)
		printf("Stack empty");
	else
	{
		top--;
		return(s[top+1]);

	}
}
void main()
{
    char E[100],x;
    int i,op1,op2,z;
    clrscr();
    printf("Enter a postfix expression ended by $:");
    scanf("%s",&E);
    i=0;
    x=E[i];
    while(x!='$')
    {
	if(x>='0'&& x<='9')
	{
	      push(x-48);
	}
	else//x is operator
	{
	     op2=pop();
	     op1=pop();
	     switch(x)
	     {
		case '+': z=op1+op2;
			  break;
		case '-': z=op1-op2;
			  break;
		case '*': z=op1*op2;
			  break;
		case '/': z=op1/op2;
			  break;
		case '^': z=1;
			  for(j=1;j<=op2;j++)
				z=z*op1;

	     }
	     push(z);
	}
	i++;
	x=E[i];
    }
    printf("The result is:%d",s[top]);
    getch();
}
















