#include<stdio.h>
#include<stdlib.h>
int max=10;
int parent[10];

int adv[10][10];
typedef struct
{
	int v;
	int e;
	int w;
}edge;
typedef struct{
	edge edgearray[10];
	int n;
}edgelist;
edgelist *list;
void sort()
{
	int n=1,i,j;
	while(n)
	{
		n=0;
		for(i=0;i<16;i++)
		{
			j=i+1;
			if(list->edgearray[i].w>list->edgearray[j].w)
			{
				list->edgearray[i]=list->edgearray[j];
				n=1;
			}
		}
	}
}
edgelist *create()
{
	int i,j;
	//printf("%d",node->v);
	//printf("Enter the no of edges: ");
	//scanf("%d",&node->e);
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
		adv[i][j]=0;
	}
}
list =(edgelist *)malloc(16*sizeof(edgelist));
	//printf("I am here 2\n");
	//printf("I am here 1\n");
	/*for(i=0;i<node->e;i++)
	{
		int x,y,w;
		printf("Enter the edges: ");
		scanf("%d %d",&x,&y);
		printf("Enter the Weight: ");
		scanf("%d",&w);
		if(x>=node->v || y>=node->v)
		{
			printf("Origin vertex do not exist\n");
			continue;
		}
		node->adv[x][y]=w;
	}*/
	list->n=0;
	adv[0][2]=9;
	adv[0][1]=8;
	adv[0][4]=7;
	adv[2][1]=-4;
	adv[2][0]=5;
	adv[2][3]=3;
	adv[3][2]=6;
	adv[3][1]=3;
	adv[3][5]=4;
	adv[1][5]=9;
	adv[4][7]=16;
	adv[5][7]=5;
	adv[5][6]=-8;
	adv[5][0]=4;
	adv[6][3]=5;
	adv[6][7]=2;
	for(i=0;i<max;i++)
	for(j=0;j<max;j++)
	{
		if(adv[i][j]!=0)
		{
			list->edgearray[list->n]->e=i;
			list->edgearray[list->n]->v=j;
			list->edgearray[list->n]->w=adv[i][j];
			list->n++;
		}
	}
	return list;
}
int find(int index)
{
	int a=parent[index];
	if(a==-1)
	return index;
	find(parent,parent[index]);
}
void unionn(int first,int last)
{
	int x=find(parent,first);
	int y=find(parent,last);
	parent[x]=y;
}
int main()
{
	int i;
	edgelist *root=create();
    sort();
	for(i=0;i<max;i++)
	{
		parent[i]=-1;
	}
	for(i=0;i<root->v;i++)
	{
		if(find(list->edgearray[i]->e)!=find(list->edgearray[i]->v))
		{
			unionn(list->edgearray[i]->e,list->edgearray[i]->v);
		}
	}
	i=0;
	while(i!=edgelist->n)
	{
		if(parent[i]!=0)
		printf("%d--%d",i,parent[i]);
		i++;
	}
	return 0;
}
