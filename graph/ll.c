#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
int a[10];
int b[10];
struct edge{
	int data;
	struct edge *next;
};
struct graph{
	struct edge *ar[8];
	int v;
};
typedef struct
{
	int data;
	struct queue *next;
}queue;
queue *head=NULL,*end=NULL;
struct graph *root=NULL;
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
void create(int v)
{
	int i;
	for(i=0;i<v;i++)
	{
		root->ar[i]=(struct edge *)malloc(sizeof(struct edge));
		root->ar[i]->data=i;
		root->ar[i]->next=NULL;
		a[i]=initial;
		b[i]=initial;
	}
}
void addedge(int v,int e)
{
	struct edge *temp=(struct edge*)malloc(sizeof(struct edge));
	temp->data=e;
	temp->next=root->ar[v]->next;
	root->ar[v]->next=temp;
}
void display()
{
	int i;
	for(i=0;i<root->v;i++)
	{
		printf("%d----\n",root->ar[i]->data);
		struct edge *temp=root->ar[i]->next;
		while(temp!=NULL)
        {
			printf("%d->%d  ",root->ar[i]->data,temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void BFS(int v)
{

	insert(root->ar[v]->data);
	while(head!=NULL)
	{
		int q=head->data;
		del();
		printf("%d\n",q);
		a[q]=visited;
		struct edge *temp=root->ar[q]->next;
		while(temp!=NULL)
		{
			if(a[temp->data]==initial){
			insert(temp->data);
			a[temp->data]=waiting;
		}
			temp=temp->next;
		}
	}
}
void DFS(int v)
{
	if(root->ar[v]->next==NULL)
	{
		printf("%d\n",root->ar[v]->data);
		b[root->ar[v]->data]=visited;
		return;
	}
	printf("%d\n",root->ar[v]->data);
	b[root->ar[v]->data]=visited;
	struct edge *temp=root->ar[v]->next;
	while(temp!=NULL)
{
	if(b[temp->data]==initial)
	DFS(temp->data);
	temp=temp->next;
}
}
int main()
{
	root=(struct graph *)malloc(sizeof(struct graph));
	root->v=4;
	create(5);
	addedge(0,2);
	addedge(0,1);
	//addedge(0,5);
	addedge(1,2);
	//addedge(1,5);
	addedge(2,3);
	addedge(1,3);
	addedge(3,4);
	display();
	BFS(0);
	printf("Depth first search: \n");
	DFS(0);
	printf("Exit\n");
	return 0;
}
