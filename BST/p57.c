#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree* ar2bst(int a[],int left,int right);
void inorder(struct tree* temp);
int main()
{
	int n,i;
	printf("Enter the no of elements in the array: ");
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	struct tree *root=ar2bst(a,0,n-1);
	inorder(root);
	return 0;
}
struct tree* ar2bst(int a[],int left,int right)
{
	if(left>right)
	return NULL;
	struct tree *newnode=(struct tree *)malloc(sizeof(struct tree));
	int mid=(left+right)/2;
	if(left==right)
	{
		newnode->data=a[mid];
		newnode->left=newnode->right=NULL;
	}
	else
	{
		newnode->data=a[mid];
		newnode->left=ar2bst(a,left,mid-1);
		newnode->right=ar2bst(a,mid+1,right);
	}
	return newnode;
}
void inorder(struct tree* temp)
{
//	printf(" I am here 9");
	if(temp==NULL)
	return;
//printf(" I am here 11");
	inorder(temp->left);
//	printf(" I am here 10");
	printf("%d\n",temp->data);
	inorder(temp->right);
}
