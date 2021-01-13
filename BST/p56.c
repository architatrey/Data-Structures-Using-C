#include<stdio.h>
#include<stdlib.h>
struct DoublyLinkedListNode {
      int data;
      struct DoublyLinkedListNode* next;
      struct DoublyLinkedListNode* prev;
  };
  int isgreator(struct DoublyLinkedListNode *node,int min,int max);
  int isbinary(struct DoublyLinkedListNode *node);
struct DoublyLinkedListNode* newnode(struct DoublyLinkedListNode *head,int data);
struct DoublyLinkedListNode* mid(struct DoublyLinkedListNode *head,int n);
int main()
{
	struct DoublyLinkedListNode *head=NULL;
	int n;
	printf("Enter the no of Elements: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		head=newnode(head,d);
	}
//	printf(" I am here 1");
	struct DoublyLinkedListNode *temp=mid(head,n); 
	dll2bst(head,temp);
//	printf(" I am here 2");
	inorder(temp);
//	printf(" I am here 3");
printf("isbinary=%d",isbinary(temp));
	return 0;
}
struct DoublyLinkedListNode* newnode(struct DoublyLinkedListNode *head,int dat)
{
	struct DoublyLinkedListNode *t=head;
	if(t==NULL)
	{
		struct DoublyLinkedListNode *temp=(struct DoublyLinkedListNode *)malloc(sizeof(struct DoublyLinkedListNode *));
		temp->data=dat;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
	while(t->next!=NULL)
	{
	t=t->next;}
	struct DoublyLinkedListNode *temp=(struct DoublyLinkedListNode *)malloc(sizeof(struct DoublyLinkedListNode *));
	t->next=temp;
	temp->data=dat;
	//printf("%d is accepted\n",temp->data);
	temp->next=NULL;
	temp->prev=t;
	return head;
}
struct DoublyLinkedListNode* mid(struct DoublyLinkedListNode *head,int n)
{
	if(head==NULL)
	return NULL;
//	printf(" I am here 4");
	int i=0;
	while(i!=n/2)
	{
		head=head->next;
		i++;
	}
//	printf(" I am here 5");
	return head;
}
void dll2bst(struct DoublyLinkedListNode *head,struct DoublyLinkedListNode *mid)
{
	head=mid;
	if(head==NULL)
	return;
//	printf(" I am here 6");
while(head->prev->prev!=NULL)
	{
		struct DoublyLinkedListNode * temp;
		temp=head->prev->prev;
	head->prev->next=NULL;
	head->prev->prev=NULL;
	head->prev=temp;
	head=temp;
//	printf(" I am here 7");
}
if(head->prev!=NULL)
{
head->prev->next=NULL;
	head->prev->prev=NULL;
}
head=mid;
while(head->next!=NULL && head->next->next!=NULL)
{
//	printf(" I am here 8");
	struct DoublyLinkedListNode * temp;
	temp=head->next->next;
	head->next->next=NULL;
	head->next->prev=NULL;
	head->next=temp;
	head=temp;
//	printf("I am here 14");
}
if(head->next!=NULL)
{
head->next->next=NULL;
	head->next->prev=NULL;
}
//printf("I am here 15");
}
void inorder(struct DoublyLinkedListNode* temp)
{
//	printf(" I am here 9");
	if(temp==NULL)
	return;
//printf(" I am here 11");
	inorder(temp->prev);
//	printf(" I am here 10");
	printf("%d\n",temp->data);
	inorder(temp->next);
}
int isbinary(struct DoublyLinkedListNode *node)
{
	if(isgreator(node,-100,1000000))
	return 1;
	else 
	return 0;
}
int isgreator(struct DoublyLinkedListNode *node,int min,int max)
{
	if(node==NULL)
	return 1;
	if(node->data>min && node->data<max && isgreator(node->prev,min,node->data) && isgreator(node->next,node->data,max))
	{
	      return 1;
	}
	else
	return 0;
}
