#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
};
struct tree *insert(struct tree* node,int data);
struct tree *newnode(int data);
int togreatbst(struct tree *node,int sum);
void inorder(struct tree*);
int main()
{
	printf("Enter the no of Elements: ");
	int n,i;
	struct tree *root=NULL;
	scanf("%d",&n);
	int sum=0;
	for(i=0;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		sum+=d;
		root=insert(root,d);
	}
	printf("Sum=%d",sum);
	togreatbst(root,sum);
	inorder(root);
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
int togreatbst(struct tree *node,int sum)
{
	if(node==NULL)
	return sum;
	sum=togreatbst(node->left,sum);
	node->data=sum-node->data;
	sum=node->data;
	sum=togreatbst(node->right,sum);
}
void inorder(struct tree* node)
{
	if(node==NULL)
	return;
	inorder(node->left);
	printf("%d\n",node->data);
	inorder(node->right);
}
