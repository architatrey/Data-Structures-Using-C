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
struct tree *removehalfnode(struct tree *root);
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
	root=removehalfnode(root);
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
struct tree *removehalfnode(struct tree *root)
{
	if(root==NULL)
	return root;
	root->left=removehalfnode(root->left);
	root->right=removehalfnode(root->right);
	if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	if(root->left==NULL && root->right!=NULL)
	{
		struct tree *temp=root->right;
		free(root);
		return temp;
	}
	if(root->left!=NULL && root->right==NULL)
	{
	struct tree *temp=root->left;
		free(root);
		return temp;
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
