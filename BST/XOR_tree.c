#include<stdio.h>
#include<stdlib.h>
struct XOR{
	int data;
	struct XOR *left;
	struct XOR *right;
};
struct XOR *insert(struct XOR *root,int data);
struct XOR *Xor(struct XOR *temp1,struct XOR *temp2);
int main()
{
	int n;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	struct XOR *root=NULL;
	while(n!=0)
	{
		int d;
		printf("enter the no: ");
		scanf("%d",&d);
		root=insert(root,d);
		n--;
	}
	struct XOR *temp=Xor(root->left,NULL);
	printf("%d\n",Xor(temp->left,root)->data);
	return 0;
}
struct XOR *Xor(struct XOR *temp1,struct XOR *temp2)
{
	int d1=temp1,d2=temp2;
	temp1=d1^d2;
	return temp1;
}
struct XOR *insert(struct XOR *root,int data)
{
	struct XOR *temp=(struct XOR *)malloc(sizeof(struct XOR));
	temp->data=data;
	temp->left=temp->right=NULL;
	if(root==NULL)
	{
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	struct XOR *ptr=root,*parent=NULL;
	while(ptr->left!=NULL && ptr->right!=NULL)
	{
		if(ptr->data<data)
		{
			struct XOR *temp2=ptr;
			ptr=Xor(ptr->right,parent);
			parent=temp2;
		}
		else
		{
			struct XOR *temp2=ptr;
			ptr=Xor(ptr->left,parent);
			parent=temp2;
		}
	}
	if(data<ptr->data)
	{
		ptr->left=Xor(parent,temp);
	}
	else
	ptr->right=Xor(parent,temp);
	return root;
}
