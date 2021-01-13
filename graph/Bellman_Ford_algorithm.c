#include<stdio.h>
#include<stdlib.h>
#define infinity 999999
#define nul -1
int pre[10],distance[10];
typedef struct
{
	int v;
	int e;
	int **adv;
}graph;
typedef struct
{
	int data;
	struct queue *next;
}queue;
queue *head=NULL,*end=NULL;
void insert(int a)
{
	//printf("I a herer 7\n");
	queue *temp=(queue*)malloc(sizeof(queue*));
	//printf("I a herer 8\n");
	if(temp==NULL)
	{
		printf("Overflow");
		return;
	}
	if(head==NULL)
	{
		temp->data=a;
		temp->next=NULL;
		head=temp;
		end=temp;
	//	printf("I a herer 9\n");
		return;
	}
	temp->data=a;
	temp->next=NULL;
	end->next=temp;
	end=temp;
	//printf("I a herer 10\n");
}
void del()
{
	if(head==NULL)
	{
		printf("\nNot enough elements");
		return;
	}
	queue *temp;
	temp=head;
	head=temp->next;
	free(temp);
}
void del();
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
void shortestpath(graph *root,int s)
{
	if(root==NULL)
	return;
	int i;
	//printf("I am here 5\n");
	for(i=0;i<root->v;i++)
	{
		distance[i]=infinity;
		pre[i]=nul;
	}
	//printf("I am here 6\n");
	distance[s]=0;
	insert(s);
	//printf("I am here 7\n");
	while(head!=NULL)
	{
		int v=head->data;
		del();
		for(i=0;i<root->v;i++)
		{
			if(root->adv[v][i]!=0)
			{
	//			printf("I am here 1\n");
				int temp=distance[v]+root->adv[v][i];
				if(temp<distance[i])
				{
	//				printf("I am here 2\n");
					distance[i]=temp;
					pre[i]=v;
					insert(i);
				}
			}
	//		printf("I am here 4\n");
		}
	//	printf("I am here 3\n");
	}
}
void path(int v,int s)
{
	while(1)
	{
		printf("%d->",v);
		if(v==s)
		{
			printf("\b\b");
		return;
	}
		v=pre[v];
	}
}
int main()
{
	graph *root=create();
	display(root);
	shortestpath(root,0);
	int i;
	for(i=0;i<root->v;i++)
	{
		printf("distance of 0 from %d is %d\n",i,distance[i]);
		printf("Path---\n");
		path(i,0);
	}
	return 0;
}
