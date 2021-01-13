#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int value;
	int key;
	struct PriorityQueue *next;
}PriorityQueue;
PriorityQueue *create(PriorityQueue *head,int key,int value)
{
	PriorityQueue *temp=(PriorityQueue*)malloc(sizeof(PriorityQueue));
	temp->value=value;
	temp->key=key;
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
		return head;
	}
	PriorityQueue *ptr=head;
	while(ptr->next!=NULL && key>ptr->key)
	{
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next=temp;
	return head;
}
PriorityQueue *pop(PriorityQueue *head)
{
	if(head==NULL)
	{
		printf("Memory Underflow\n");
		return NULL;
	}
	PriorityQueue *temp=head->next;
	free(head);
	return temp;
}
int main()
{
	PriorityQueue *head=NULL;
	head=create(head,1,19);
	head=create(head,4,27);
	head=create(head,2,76);
	head=create(head,3,51);
	printf("%d\n",head->value);
	head=pop(head);
	printf("%d\n",head->value);
	head=pop(head);
	printf("%d\n",head->value);
	head=pop(head);
	return 0;
}
