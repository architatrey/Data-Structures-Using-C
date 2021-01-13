#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
jmp_buf f;
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
void kth(struct tree *,int data);
static int no=0;
struct tree *head=NULL;
struct tree *insert(struct tree *node,int data);
struct tree *newnode(int data);
int main()
{
	
	struct tree *root=NULL;
	int n;
	printf("Enter the no elements in the tree: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int d;
	scanf("%d",&d);
		root=insert(root,d);
   }
   int d;
   printf("Enter the value: ");
   scanf("%d",&d);
   if(setjmp(f)==0)
   kth(root,d);
   else
   printf("no =%d",no);
	return 0;
}
int i=0;
void kth(struct tree *node,int data)
{
	if(node==NULL)
	return;
	kth(node->left,data);
	i++;
	printf("i=%d",i);
	if(i==data)
	{
		no=node->data;
		longjmp(f,1);
	}
	kth(node->right,data);
}
struct tree *insert(struct tree* node,int data)
{
	if(node==NULL)
	{
		node=newnode(data);
	}
	else if(data<=node->data)
	{
		node->left=insert(node->left,data);
	}
	else
	{
		node->right=insert(node->right,data);
	}
	return node;
}
struct tree *newnode(int data)
{
	struct tree *temp=(struct tree *)malloc(sizeof(struct tree));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
