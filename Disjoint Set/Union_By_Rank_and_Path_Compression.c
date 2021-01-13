#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int v;
	int e;
	int **adv;
}graph;
typedef struct subset{
	int parent;
	int rank;
};
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
int find(subset *x[],int value)
{
	int y=x[value]->parent;
	if(y==value)
	return value;
	return find(x,y);
}
void unionn(subset *subsets,int first,int last)
{
	if(subsets[first]->rank>subsets[last]->rank)
	{
		subsets[last]->parent=first;
	}
	else if(subsets[last]->rank>subsets[first]->rank)
	{
		subsets[first]->parent=last;
	}
	else
	{
		subsets[last]->parent=first;
		subsets[first]->rank++;
	}
}
int iscycle(graph *root,subset *subsets)
{
	
	for(i=0;i<root->v;i++)
	{
		subsets[i]->parent=i;
	    subsets[i]->rank=0;
	}
	for(i=0;i<root->v;i++)
	{
		for(j=0;j<root->v;j++)
		{
			if(root->adv[i][j]!=0)
			{
				int x=find(subsets,i);
				int y=find(subsets,j);
				if(i==j)
				return 1;
				unionn(subsets,x,y);
			}
		}
	}
}
int main()
{
	graph *root=create();
	subset *subsets=(subset *)malloc(root->v*sizeof(subset));
	if(iscycle(root,subsets))
	return 0;
}
