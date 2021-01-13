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
void main()
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
	printf("bye..");
	free(root);
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
void shortpath(graph *root,int v)
{
	int i;
	for(i=0;i<root->v;i++)
	{
		if(i!=v){
		
		shortar[i]=infinity;
		status[i]=temporary;}
	}
	shortar[v]=0;
	status[v]=permanent;
	int current=v,temp=root->v;
	while(temp!=0)
	{
		for(i=0;i<root->v;i++)
		{
			if(root->adv[current][i]!=0 && status[i]==temporary)
			{
				int temp2=shortar[current]+root->adv[current][i];
				if(temp2<shortar[i])
				shortar[i]=temp2;
			}
		}
		printf("I am herw 4\n");
		int temp2=infinity;
		temp=0;
		int p=infinity;
		int z=0;
		printf("I am herw 3\n");
		for(i=0;i<root->v;i++)
		{
			printf("I am herw 1\n");
			if(status[i]==temporary){
				temp++;
			printf("I am herw 2\n");
			if(temp2>shortar[i]){
				printf("I am here 6\n");
			p=i;
			temp2=shortar[i];
			printf("I am here 7\n");
		}
			if(shortar[i]==infinity)
			{
				z++;
			}
		}
		}
		if(z==temp)
		break;
		printf("p=%d\n",p);
		status[p]=permanent;
		current=p;
		printf("z=%d temp=%d\n",z,temp);
	}
}
