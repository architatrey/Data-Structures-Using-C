#include<stdio.h>
#include<stdlib.h>
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
int ar[20];
int indegree[20];
void insert(int);
void del();
graph *create();
queue *end=NULL,*head=NULL;
void indegre(graph *root)
{
	int i,j,count=0;
	for(j=0;j<root->v;j++)
	for(i=0;i<root->v;i++)
	{
		// printf("I am here 3\n");
		if(root->adv[j][i]==1)
		indegree[i]++;
	}
}
void dele(graph *root);
int main()
{
	graph *root=create();
	int i,count=0;
	indegre(root);
	for(i=0;i<root->v;i++)
	{
		if(indegree[i]==0)
		insert(i);
	}
	while(head!=NULL)
	{
		int d=head->data;
		del();
		ar[count++]=d;
		for(i=0;i<root->v;i++)
		{
			// printf("I a, here 1\n");
			if(root->adv[d][i]==1)
			{
				// printf("I a, here 1\n");
				if(--indegree[i]==0)
				insert(i);
			}
		}
		// printf("I a, here 1\n");
	}
	for(i=0;i<root->v;i++)
	 printf("%d\n",ar[i]);
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
void dele(graph *root)
{
	int x,y;
	printf("Enter the edge to be deleted: ");
	scanf("%d %d",&x,&y);
	root->adv[x][y]=0;
}
void insert(int a)
{
	printf("I a herer 7\n");
	queue *temp=(queue *)malloc(sizeof(queue));
	printf("I a herer 8\n");
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
		// printf("I a herer 9\n");
		return;
	}
	temp->data=a;
	temp->next=NULL;
	end->next=temp;
	end=temp;
	// printf("I a herer 10\n");
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
