#include<stdio.h>
#include<stdlib.h>
struct TBT{
	int data;
	struct TBT *left;
	struct TBT *right;
	int lthread;
	int rthread;
};
struct TBT *insucess(struct TBT *ptr)
{
	if(ptr==NULL)
	return NULL;
	ptr=ptr->right;
	while(ptr->lthread!=1)
	{
		ptr=ptr->left;
	}
	return ptr;
}
struct TBT *inpred(struct TBT *ptr)
{
	if(ptr==NULL)
	return NULL;
	ptr=ptr->left;
	while(ptr->rthread!=1)
	{
		ptr=ptr->right;
	}
	return ptr;
}
struct TBT *insert(struct TBT *root,int data)
{
	struct TBT *temp=(struct TBT *)malloc(sizeof(struct TBT));
	temp->data=data;
	if(root==NULL)
	{
		temp->left=temp->right=NULL;
		temp->lthread=temp->rthread=1;
		return temp;
	}
	struct TBT *ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->data<data)
	{   if(ptr->rthread==0)
		ptr=ptr->right;
		else
		break;
	}
		else if(data<ptr->data)
	{
		if(ptr->lthread==0)
		ptr=ptr->left;
		else
		break;
    }
		else
		{
			printf("Duplicate\n");
		}
	}
	if(data<ptr->data)
	{
		temp->left=ptr->left;
		ptr->left=temp;
		temp->right=ptr;
		temp->lthread=temp->rthread=1;
		ptr->lthread=0;
		return root;
	}
	else if(data>ptr->data)
	{
		temp->right=ptr->right;
		ptr->right=temp;
		temp->left=ptr;
		temp->lthread=temp->rthread=1;
		ptr->rthread=0;
		return root;
	}
}
void inorder(struct TBT *root)
{
	if(root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	while(root->left!=NULL)
	{
	    root=root->left;
	}
	int i=0;
	while(i!=11)
	{
		printf("%d\n",root->data);
		if(root->right==NULL)
		break;
		if(root->rthread==1)
		root=root->right;
		else
		{
			root=insucess(root);
		}
		i++;
	}
	return;
}
struct TBT *delNode(struct TBT *root,struct TBT *ptr2)
{
	if(ptr2->rthread==1 && ptr2->lthread==1)
	{
		struct TBT *parent;
		if(ptr2==ptr2->left->right)
		parent=ptr2->left;
		else
		parent=ptr2->right;
		printf("parent=%d",parent->data);
		if(ptr2==parent->left)
		{
			parent->left=ptr2->left;
			parent->lthread=1;
			free(ptr2);
		return root;
		}
		else
		{
			parent->right=ptr2->right;
			parent->rthread=1;
			free(ptr2);
		    return root;
		}
	}
	if(ptr2->lthread==0 && ptr2->rthread==1)
	{
		struct TBT *ptr=inpred(ptr2);
		printf("prede=%d",ptr->data);
		int i=ptr->data;
		root=delNode(root,ptr);
		ptr2->data=i;
		return root;
	}
	else if(ptr2->rthread==0 && ptr2->lthread==1)
	{
		struct TBT *ptr=insucess(ptr2);
		int i=ptr->data;
		root=delNode(root,ptr);
		ptr2->data=i;
		return root;
	}
		if(ptr2->rthread==0 && ptr2->lthread==0)
	{
		struct TBT *ptr=insucess(ptr2);
		ptr2->data=ptr->data;
		root=delNode(root,ptr);
	/*	if(parent==root)
		root=ptr2;*/
		return root;
	}
}
struct TBT *del(struct TBT *root,int data)
{
	if(root==NULL)
	{
		printf("To few elements to perform this operation ");
		return;
	}
	struct TBT *ptr2=root,*parent=root;
	while(1)
	{
		if(data==ptr2->data)
		{
			root=delNode(root,ptr2);
			return root;
		}
		if(data<ptr2->data)
		{
			if(ptr2->lthread==0)
			{
				parent=ptr2;
				ptr2=ptr2->left;
			}
			else
			{
				printf("element not present\n");
				return root;
			}
		}
		else if(data>ptr2->data)
		{
			if(ptr2->rthread==0)
			{
				parent=ptr2;
				ptr2=ptr2->right;
			}
			else
			{
				printf("element not present\n");
				return root;
			}
		}
	}
}
int main()
{
	struct TBT *root=NULL;
	int n;
	printf("Enter the no elements: ");
	scanf("%d",&n);
	while(n!=0)
	{
		int d;
		printf("Enter the element: ");
		scanf("%d",&d);
		root=insert(root,d);
		n--;
	}
	inorder(root);
	int i=3;
	while(i!=0)
	{
		printf("Enter the element to delete: ");
		scanf("%d",&n);
		root=del(root,n);
		inorder(root);
		i--;
	}
	return 0;
}
