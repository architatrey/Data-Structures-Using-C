#include<stdio.h>
#include<stdlib.h>
#define infinity 999999
#define nul -1
int pred[8][8];
int shortar[8][8];
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
	node->adv[0][1]=2;
	node->adv[0][3]=9;
	node->adv[2][1]=6;
	node->adv[3][0]=14;
	node->adv[2][3]=2;
	node->adv[3][2]=4;
	node->adv[1][0]=3;
	node->adv[1][3]=7;
	node->adv[1][2]=4;
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
void shortestpath(graph *root)
{
	if(root==NULL)
	return;
	int i,j,k;
	for(i=0;i<root->v;i++)
	{
		for(j=0;j<root->v;j++)
		{
			if(root->adv[i][j]!=0)
			{
				shortar[i][j]=root->adv[i][j];
				pred[i][j]=i;
			}
			else
			{
				pred[i][j]=nul;
				shortar[i][j]=infinity;
			}
		}
	}
	for(k=0;k<root->v;k++){
	for(i=0;i<root->v;i++)
	{
		for(j=0;j<root->v;j++)
		{
			int temp=shortar[i][k]+shortar[k][j];
			if(temp<shortar[i][j])
			{
				shortar[i][j]=temp;
				pred[i][j]=pred[k][j];
			}
		}
	}
}
}
int main()
{
	graph *root=create();
	display(root);
	shortestpath(root);
	int i,j;
	printf("\n\n\nshortest path matrix\n");
	for(i=0;i<root->v;i++)
	{
		for(j=0;j<root->v;j++)
		{if(shortar[i][j]==infinity)
		printf("Infinity\t");
		else
		printf("%d\t",shortar[i][j]);}
		printf("\n");
	}
	printf("\n\n\npred matrix: \n");
	for(i=0;i<root->v;i++)
	{
		for(j=0;j<root->v;j++)
		{if(pred[i][j]==nul)
		printf("nul\t");
		else
		printf("%d\t",pred[i][j]);
		}
		printf("\n");
	}
	return 0;
}
