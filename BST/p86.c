#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
};
struct tree *temp=NULL;
struct tree *insert(struct tree* node,int data);
struct tree *newnode(int data);
struct tree *removebw(struct tree *root,int min,int max);
void preorder(struct tree *root);
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
	preorder(root);
	int min,max;
	printf("Enter the min and max: ");
	scanf("%d %d",&min,&max);
	root=removebw(root,min,max);
	preorder(root);
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
struct tree *removebw(struct tree *root,int min,int max)
{
	if(root==NULL)
	return NULL;
	if(root->data<min)
	{
		root=removebw(root->right,min,max);
		return root;
	}
	else if(root->data>max)
	{
		root=removebw(root->left,min,max);
		return root;
	}
	else
	{
		root->left=removebw(root->left,min,max);
		root->right=removebw(root->right,min,max);
		return root;
	}
	return root;
}
void preorder(struct tree *root)
{
	if(root==NULL)
	{
		return;
	}
	preorder(root->left);
	printf("%d\n",root->data);
	preorder(root->right);
}
