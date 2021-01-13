#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
int control=0;
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
void insert(int);
void del();
queue *end=NULL,*head=NULL;
int proc[25];
graph *create();
void BFS(graph *root,int v);
void display(graph *node);
void dele(graph *root);
int main()
{
	graph *root=create();
	display(root);
	int k=1;
	while(k){
		scanf("%d",&k);
	printf("Enter the value of vertex: ");
	int v,i;
	scanf("%d",&v);
	printf("Breadth first search-----\n");
	for(i=0;i<root->v;i++)
	{
		proc[i]=initial;
	//	printf("I a herer 1\n");
	}
	BFS(root,v);
}
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
	printf("Enter the no of edges: ");
	scanf("%d",&node->e);
	for(i=0;i<node->v;i++)
	{
		for(j=0;j<node->v;j++)
		{
		node->adv[i][j]=0;
		//printf("I am here 1\n");
	}
	//printf("I am here 2\n");
	}
	//printf("I am here 1\n");
	for(i=0;i<node->e;i++)
	{
		int x,y;
		printf("Enter the edges: ");
		scanf("%d %d",&x,&y);
		if(x>=node->v || y>=node->v)
		{
			printf("Origin vertex do not exist\n");
			continue;
		}
		node->adv[x][y]=1;
	}
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
void dele(graph *root)
{
	int x,y;
	printf("Enter the edge to be deleted: ");
	scanf("%d %d",&x,&y);
	root->adv[x][y]=0;
}
void BFS(graph *root,int v)
{
	//printf("I a herer 10\n");
	insert(v);
	//printf("I a herer 2\n");
	proc[v]=waiting;
	//printf("I a herer 3\n");
	while(head!=NULL)
	{
	int u=head->data;
	//if(control>=50)
	//exit(0);
	//printf("I a herer 4\n");
	del();
	proc[u]=visited;
	//printf("I a herer 5\n");
	printf("%d\n",u);
	int i;
	for(i=0;i<root->v;i++)
	{
		//printf("I a herer 11\n");
		if(root->adv[u][i]==1 && proc[i]==initial)
		{
		//	printf("I a herer 6\n");
			insert(i);
			proc[i]=waiting;
		}
		/*if(control>=50)
		break;
		control++;*/
	}
}
}
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
