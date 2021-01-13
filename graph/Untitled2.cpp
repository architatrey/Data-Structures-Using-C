#include<stdio.h>
#include<stdlib.h>
struct list{
	int key;
	struct list *next;
};
typedef struct{
	int v;
	int e;
	struct list *head[];
}graph;
graph *insert(graph *root,int x,int y);
graph *create();
void display(graph *root);
int main()
{
	graph *root=create();
	void display(root);
	return 0;
}
graph *create()
{
	graph *temp=(graph *)malloc(sizeeof(graph));
	printf("Enter the no of Vertices: ");
	scanf("%d"&temp->v);
	int i;
	temp->head[temp->v]=(struct list *)malloc(sizeof(struct list));
	for(i=0;i<temp->v;i++)
	{
		scanf("%d",&temp->head[i]->key);
		temp->head[i]->next=NULL;
	}
	printf("Enter the no of edges: ");
	scanf("%d",&temp->e);
	for(i=0;i<temp->e;i++)
	{
		int x,y,weight;
		printf("Enter the edges: ");
		scanf("%d %d",&x,&y);
		temp=insert(root,x,y);
	}
	return temp;
}
graph *insert(graph *root,int x,int y)
{
	struct list *temp=root->head[x];
	if(temp->next==NULL)
	{
		struct list *temp2=(struct list *)malloc(sizeof(struct list));
		temp2->key=y;
		temp2->next=NULL;
		root->head[x]=temp2;
		return root;
	}
	struct list *temp2=(struct list *)malloc(sizeof(struct list));
		temp2->key=y;
		temp2->next=temp->next;
		temp->next=temp2;
		root->head[x]=temp2;
		return root;
}
void display(graph *root)
{
	int i;
	for(i=0;i<root->v;i++)
	{
		struct list *temp=root->head[i]->next;
		while(temp!=NULL)
		{
			printf("%d->%d",root->head[i]->key,temp->key);
			temp=temp->next;
		}
		printf("\n");
	}
}
