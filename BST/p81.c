#include<stdio.h>
#include<stdlib.h>
int diff=1000;
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
};
struct tree *temp=NULL;
struct tree *insert(struct tree* node,int data);
struct tree *newnode(int data);
void closest(int data,struct tree *);
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
	int d;
	printf("Enter the value u want to search for: ");
	scanf("%d",&d);
	closest(d,root);
	printf("\nclosest()=%d",temp->data);
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
void closest(int data,struct tree *root)
{
	if(root==NULL)
	return root;
	else if(data==root->data)
	{
		diff=0;
		temp=root;
	return;
}
	else if(data<root->data)
	{
		if(diff>abs(data-root->data))
		{
		temp=root;
		diff=abs(data-root->data);
	}
		closest(data,root->left);
	}
	else
	{
		if(diff>abs(data-root->data))
		{
			temp=root;
			diff=abs(data-root->data);
		}
		closest(data,root->right);
	}
}
