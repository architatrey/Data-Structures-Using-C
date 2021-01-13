#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int v;
	int e;
	int **adv;
}graph;
graph *create()
{
	graph *node=(graph *)malloc(sizeof(graph));
	if(node==NULL)
	{
		printf("Memeory Error: ");
		return NULL;
	}
	printf("Enter the no of vertices: ");
	scanf("%d",&node->v);
	int i,j;
	//printf("%d",node->v);
	node->adv=(int **)malloc(node->v*sizeof(int *));
	for(i=0;i<node->v;i++)
	{
		node->adv[i]=(int *)malloc(sizeof(int));
	}
	//printf("Enter the no of edges: ");
	//scanf("%d",&node->e);
	for(i=0;i<node->v;i++)
	{
		for(j=0;j<node->v;j++)
		{
		node->adv[i][j]=0;
	}
}
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
node->adv[0][2]=9;
	node->adv[0][1]=8;
	node->adv[0][4]=7;
	node->adv[2][1]=-4;
	node->adv[2][0]=5;
	node->adv[2][3]=3;
	node->adv[3][2]=6;
	node->adv[3][1]=3;
	node->adv[3][5]=4;
	node->adv[1][5]=9;
	node->adv[4][7]=16;
	node->adv[5][7]=5;
	node->adv[5][6]=-8;
	node->adv[5][0]=4;
	node->adv[6][3]=5;
	node->adv[6][7]=2;
	return node;
}
void display(graph *node)
{
	int i,j;
	for(i=0;i<node->v;i++){
	for(j=0;j<node->v;j++)
	{
		printf("%4d ",node->adv[i][j]);
	}
	printf("\n");
}
}
int find(int parent[],int index)
{
	int a=parent[index];
	if(a==-1)
	return index;
	find(parent,parent[index]);
}
void unionn(int parent[],int first,int last)
{
	int x=find(parent,first);
	int y=find(parent,last);
	parent[x]=y;
}
int iscycle(graph *root,graph *parent)
{
	int i,j;
	for(i=0;i<root->v;i++)
	{
		for(j=0;j<root->v;j++)
		{
			if(root->adv[i][j]!=0)
			{
				int x=find(parent,i);
				int y=find(parent,j);
				if(x==y)
				{
				printf("i=%d j=%d x=%d y=%d\n",i,j,x,y);
				return 1;}
				unionn(parent,x,y);
			}
		}
	}
}
int main()
{
	graph *root=create();
	int parent[8];
	display(root);
	int i;
	for(i=0;i<root->v;i++)
	parent[i]=-1;
	if(iscycle(root,parent)==1)
	{
		printf("Graph contain cycle\n");
	}
	else
	printf("Grsph does not contain cycle\n");
	free(root);
	return 0;
}
//the implementation of union() and find() is naive and takes O(n) time in worst case
