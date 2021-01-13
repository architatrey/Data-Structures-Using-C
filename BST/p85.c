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
struct tree *removehalfleaf(struct tree *root);
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
	root=removehalfleaf(root);
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
struct tree *removehalfleaf(struct tree *root)
{
	if(root==NULL)
	return;
	if(root->left==NULL && root->right==NULL)
	{
		free(root);
		return NULL;
	}
	root->left=removehalfleaf(root->left);
	root->right=removehalfleaf(root->right);
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
