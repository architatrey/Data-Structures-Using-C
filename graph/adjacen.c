#include<stdio.h>
#include<stdlib.h>
struct list{
	int key;
	struct list *next;
};
struct listnode{
	struct list *head;
};
typedef struct{
	int v;
	int e;
	struct listnode *had;
}graph;
graph *insert(graph *root,int x,int y);
graph *create();
void display(graph *root);
int main()
{
	graph *root=create();
	display(root);
	return 0;
}
graph *create()
{
	graph *temp=(graph *)malloc(sizeof(graph));
	printf("Enter the no of Vertices: ");
	scanf("%d",&temp->v);
	int i;
	printf("%d\n",sizeof(temp->head[1]));
	temp->had=malloc(temp->v*sizeof(struct list));
	printf("%d\n",temp->head[4]);
	for(i=0;i<temp->v;i++)
	{
		printf("Enter the value of vertices: ");
		scanf("%d",&temp->head[i]->key);
		printf("I am here 111,%d\n",temp->head[i]->key);
		temp->head[i]->next=NULL;
	}
	printf("Enter the no of edges: ");
	scanf("%d",&temp->e);
	for(i=0;i<temp->e;i++)
	{
		int x,y;
		printf("Enter the edges: ");
		scanf("%d %d",&x,&y);
		temp=insert(temp,x,y);
	}
	return temp;
}
graph *insert(graph *root,int x,int y)
{
	struct list *temp=root->had[x]->head;
	if(temp==NULL)
	{
		struct list *temp2=(struct list *)malloc(sizeof(struct list));
		temp2->key=y;
		temp2->next=NULL;
		root->head[x]->next=temp2;
		return root;
	}
	struct list *temp2=(struct list *)malloc(sizeof(struct list));
		temp2->key=y;
		temp2->next=temp->next;
		temp->next=temp2;
		root->head[x]->next=temp2;
		return root;
}
void display(graph *root)
{
	printf("I am here 1\n");
	int i;
	for(i=0;i<root->v;i++)
	{
		printf("I am here 2,%d\n",root->head[i]->key);
		struct list *temp=root->head[i]->next;
		while(temp!=NULL)
		{
			printf("I am here 3\n");
			printf("%d->%d",root->head[i]->key,temp->key);
			temp=temp->next;
		}
		printf("\n");
	}
}
