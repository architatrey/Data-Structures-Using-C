#include<stdio.h>
#include<stdlib.h>
struct vertex{
	int data;
	struct vertex *next;
	struct edge *edge;
}*start=NULL;
struct edge{
	int data;
	struct edge *next;
};
void createvertex();
void createedge(int v,int e);
void deledge(int v,int e);
void delvertex(int v);
void display();
int main()
{
	int i=1;
	printf("Enter the choice: \n1.insert ver\n2.insert edge\n3.del edge\n4.del vertex\n\n");
	while(i)
	{
		scanf("%d",&i);
		if(i==1)
		{
			int d;
			printf("Enter the value of vertices: ");
			scanf("%d",&d);
			createvertex(d);
		}
		else if(i==2)
		{
			int e,v;
			printf("Enter the vertex & edge: ");
			scanf("%d %d",&v,&e);
			createedge(v,e);
		}
		else if(i==3)
		{
			int e,v;
			printf("Enter the vertex & edge to be deleted: ");
			scanf("%d %d",&v,&e);
			deledge(v,e);
		}
		else if(i==4)
		{
			int v;
			printf("Enter the vertex to be deleted: ");
			scanf("%d",&v);
			delvertex(v);
		}
		else if(i==5)
		display();
	}
	return 0;
}
void createvertex(int data)
{
	struct vertex *temp=(struct vertex *)malloc(sizeof(struct vertex));
	temp->data=data;
	temp->next=NULL;
	temp->edge=NULL;
	if(start==NULL)
	{
		start=temp;
		start->next=NULL;
		start->edge=NULL;
		return;
	}
	struct vertex *temp2=start;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
}
void createedge(int v,int e)
{
	struct vertex *temp=start;
	while(temp->data!=v)
	{
		temp=temp->next;
	}
	struct edge *temp2=(struct edge *)malloc(sizeof(struct edge));
	if(temp->edge!=NULL)
	temp2->next=temp->edge;
	temp2->data=e;
	temp->edge=temp2;
}
void deledge(int v,int e)
{
	if(start==NULL)
	{
		printf("Few elemnts to perform the func....");
		return;
	}
	struct vertex *temp2=start;
	while(temp2->data!=v)
	{
		temp2=temp2->next;
	}
	struct edge *ptr=temp2->edge,*prev;
	while(ptr->data!=e)
	{
		
		prev=ptr;
		ptr=ptr->next;
	}
	prev->next=ptr->next;
	free(ptr);
}
void delvertex(int v)
{
    // include the condition to del all the incoming node also
	struct vertex *temp=start,*temp2=start;
	while(temp->data!=v)
	{
		temp2=temp;
		temp=temp->next;
	}
	if(temp==start)
	{
		start=temp->next;
	}
	else
	temp2->next=temp->next;
	struct edge *ptr=temp->edge,*prev=temp->edge;
	while(ptr!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
		free(prev);
	}
	free(temp);
}
void display()
{
	struct vertex *temp=start;
	struct edge *ptr=NULL;
	while(temp!=NULL)
	{
		ptr=temp->edge;
		printf("%10d----\n",temp->data);
		while(ptr!=NULL)
		{
			printf("10%d--->%d\t",temp->data,ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
		temp=temp->next;
	}
}
