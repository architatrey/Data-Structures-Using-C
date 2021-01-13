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
int maxatnode(struct tree *root,int *res);
int maxpath(struct tree *root);
int max(int a,int b)
{
	return a>b?a:b;
}
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
	printf("Max path=%d\n",maxpath(root));
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
int maxpath(struct tree *root)
{
	if(root==NULL)
	return 0;
	int res=-1111111;
	maxatnode(root,&res);
	return res;
}
int maxatnode(struct tree *root,int *res)
{
	if(root==NULL)
	return 0;
	int l=maxatnode(root->left,res);
	int r=maxatnode(root->right,res);
	int maxsoft=max(max(l,r)+root->data,root->data);
	int max2=max(maxsoft,l+r+root->data);
	*res=max(*res,max2);
	return maxsoft;
}
