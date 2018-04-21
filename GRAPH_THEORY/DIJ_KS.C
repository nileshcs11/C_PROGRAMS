#include<stdio.h>

void print_path(int prev[],int vdest);

void main()
{

int L[100][100],r,c,vstart,vdest,n,v;
char status[100];
int dist[100],prev[100],mindist,vstar;

clrscr();
printf("Enter number of vertices:");
scanf("%d",&n);

printf("Enetr Length matrix:\n");
for(r=1;r<=n;r++)
{
	for(c=1;c<=n;c++)
	{
		scanf("%d",&L[r][c]);
	 }
}

printf("Enter Starting vertex:");
scanf("%d",&vstart);
printf("Enter Destination vertex:");
scanf("%d",&vdest);

for(v=1;v<=n;v++)
{
	status[v]='?';
	dist[v]=L[vstart][v];
	prev[v]=vstart;
}
status[vstart]='!';
dist[vstart]=0;
prev[vstart]=0;
clrscr();
printf("------------------------------------------------------------------\n");
for(v=1;v<=n;v++)
	printf("\t%d",v);
printf("\n");
printf("------------------------------------------------------------------\n");
printf("Status");
for(v=1;v<=n;v++)
	printf("\t%c",status[v]);
printf("\nDist");
for(v=1;v<=n;v++)
	printf("\t%d",dist[v]);
printf("\nPrev");
for(v=1;v<=n;v++)
	printf("\t%d",prev[v]);
printf("\n------------------------------------------------------------------\n");

while(status[vdest]!='!')
{
mindist=9999;
vstar=0;
for(v=1;v<=n;v++)
{
	if(status[v]=='?')
	{
		if(dist[v]<mindist)
		{     mindist=dist[v];
		      vstar=v;
		}
	}
}
status[vstar]='!';
for(v=1;v<=n;v++)
{
	if(status[v]=='?')
	{
		if(dist[vstar]+L[vstar][v]<dist[v])
		{
		      dist[v]=dist[vstar]+L[vstar][v];
		      prev[v]=vstar;
		}
	}
}
printf("Status");
for(v=1;v<=n;v++)
	printf("\t%c",status[v]);
printf("\nDist");
for(v=1;v<=n;v++)
	printf("\t%d",dist[v]);
printf("\nPrev");
for(v=1;v<=n;v++)
	printf("\t%d",prev[v]);
printf("\n------------------------------------------------------------------\n");

}
printf("Minimum distance between %d and %d is %d",vstart,vdest,dist[vdest]);
printf("\nMinimum Distance path is:");
getch();
print_path(prev,vdest);
printf("\b\b\b    ");
getch();
}

void print_path(int prev[],int vdest)
{
	if(prev[vdest]!=0)
	{
		print_path(prev,prev[vdest]);
	}
	printf("%d-->",vdest);

}











