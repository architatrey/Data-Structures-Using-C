#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
jmp_buf f;
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
};
struct tree *insert(struct tree* node,int data);
struct tree *newnode(int data);
void nobw(struct tree *,int ,int);
int main()
{
	struct tree* root=NULL;
	int n,i;
	printf("Enter theno of Elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		root=insert(root,d);
	}
	int n1,n2;
	printf("Enter the two values: ");
	scanf("%d %d",&n1,&n2);
	if(setjmp(f)==0)
	nobw(root,n1,n2);
	else
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
void nobw(struct tree *node,int n1,int n2)
{
	if(node==NULL)
	return;
	nobw(node->left,n1,n2);
	if(node->data>=n1 && node->data<=n2)
	{
		printf("%d\n",node->data);
	}
	nobw(node->right,n1,n2);
	if(node->data<n1 || node->data>n2)
	longjmp(f,1);
}
