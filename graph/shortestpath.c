#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
struct graph{
	int v;
	int **a;
}*root;
typedef struct
{
	int data;
	struct queue *next;
}queue;
int a[10],pred[10],d[10];
queue *head=NULL,*end=NULL;
void create(int v)
{
	root=(struct graph *)malloc(sizeof(struct graph));
	root->v=v;
	root->a=(int **)malloc(v*sizeof(int *));
	int i;
	for(i=0;i<root->v;i++)
	{
		root->a[i]=(int *)malloc(v*sizeof(int));
	}
	int j;
	for(i=0;i<root->v;i++)
	{
		for(j=0;j<root->v;j++)
		{
			root->a[i][j]=0;
		}
	}
	//printf("I am here 4\n");
}
void insert(int a)
{
	queue *temp=(queue*)malloc(sizeof(queue*));
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
		return;
	}
	temp->data=a;
	temp->next=NULL;
	end->next=temp;
	end=temp;
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
void addedge(int v,int e)
{
	root->a[v][e]=1;
	//printf("I am here 5\n");
}
void BFS(int v)
{
	//printf("I am here 1\n");
	d[v]=0;
	pred[v]=-1;
	a[v]=waiting;
	insert(v);
	while(head!=NULL)
	{
		//printf("I am here 2\n");
		int q=head->data;
		del();
		printf("%d\n",q);
		a[q]=visited;
		int i;
		for(i=0;i<root->v;i++)
		{
			//printf("I am here 7\n");
			if(root->a[q][i]==1 && a[i]==initial)
			{
				//printf("I am here 6\n");
				//printf("%d %d\n",i,q);
				insert(i);
				a[i]=waiting;
				pred[i]=q;
				d[i]=d[q]+1;
			}
		}
	}
}
int main()
{
	create(7);
	int k;
	for(k=0;k<9;k++)
	{
		a[k]=initial;
		d[k]=0;
		pred[k]=-1;
	}
	addedge(0,1);
	addedge(0,4);
	addedge(1,2);
	addedge(2,3);
	addedge(3,4);
	addedge(4,5);
	addedge(4,6);
	addedge(3,5);
	BFS(0);
	int i;
	for(i=0;i<root->v;i++)
	{
		printf("pred of %d=%d\ndis of %d=%d",i,pred[i],i,d[i]);
	}
	return 0;
}
