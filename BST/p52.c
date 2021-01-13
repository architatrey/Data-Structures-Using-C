#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
};
static struct tree *prev=NULL;
struct tree *head=NULL;
struct tree *insert(struct tree* node,int data);
struct tree *newnode(int data);
void bst2dll(struct tree *node);
int main()
{
	struct tree *root=NULL;
	int n;
	printf("Enter the no of Elements:");
	scanf("%d",&n);
	while(n!=0)
	{
		printf("Enter the element: ");
		int d;
		scanf("%d",&d);
		root=insert(root,d);
		n--;
	}
	bst2dll(root);
	struct tree *temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->right;
	}
	return 0;
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
void bst2dll(struct tree *node)
{
	if(node ==NULL)
	return;
	bst2dll(node->left);
	if(prev==NULL)
	{
		head=node;
	}
	else
	{
		node->left=prev;
		prev->right=node;
	}
	prev=node;
	bst2dll(node->right);
}
