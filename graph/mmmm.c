#include<stdio.h>
#include<stdlib.h>
#define infinity 999999
#define permanent 1
#define temporary 0
typedef struct
{
	int v;
	int e;
	int **adv;
}graph;
int shortar[20];
int status[20];
graph *create();
void display(graph *node);
void shortpath(graph *root,int v);
int main()
{
	int i;
	graph *root=create();
	display(root);
	shortpath(root,0);
	for(i=0;i<root->v;i++)
	{
		if(shortar[i]==infinity)
		{
			printf("Infinity\n");
			continue;
		}
		printf("%d\n",shortar[i]);
	}
	printf("exit\n");
	return 0;
}
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
	node->adv[0][2]=2;
	node->adv[0][3]=7;
	//node->adv[0][1]=8;
	node->adv[2][3]=4;
	node->adv[2][0]=5;
	node->adv[2][6]=3;
	node->adv[3][4]=9;
	node->adv[1][5]=16;
	node->adv[4][0]=4;
	//node->adv[4][7]=8;
	node->adv[4][5]=5;
	node->adv[6][2]=6;
	node->adv[6][3]=3;
	node->adv[6][4]=4;
	node->adv[7][6]=5;
	node->adv[7][5]=2;
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
void shortpath(graph *root,int v)
{
	int i;
	for(i=0;i<root->v;i++)
	{
		printf("I am here 1\n");
		if(i!=v)
		{
		shortar[i]=infinity;
		status[i]=temporary;
	}
	}
	shortar[v]=0;
	status[v]=permanent;
	int current=v;
	int temp=root->v;
	int tempvalue=root->v;
	printf("I am here 2\n");int itr=0;
	while(temp!=0)
	{
		int shot=infinity,p=0;
		int snext;
		printf("I am here 3\n");
		for(i=0;i<root->v;i++)
		{
			if(root->adv[current][i]!=0 && status[i]!=permanent)
			{
				printf("I am here 4\n");
				printf("I am here 8\n");
				int temp=shortar[current]+root->adv[current][i];
				printf("I am here 10\n");
				if(temp<shortar[i])
				shortar[i]=temp;
			}
		}
		printf("I am here 12\n");
		snext=infinity;
		printf("I am here 13\n");
		temp=0;
		tempvalue=0;
		for(i=0;i<root->v;i++)
		{
			printf("%d->%d,shorter=%d\n",i,status[i],shortar[i]);
			if(status[i]==temporary)
			{
			printf("I am here 7\n");
				temp++;
				if(shortar[i]==infinity)
				tempvalue++;
				if(snext>shortar[i])
				{
					snext=shortar[i];
					p=i;
				}
			}
		}
		if(temp==tempvalue)
		break;
		status[p]=permanent;
		current=p;
		printf("%d %d %d\n",temp,tempvalue,p);
	}
}
