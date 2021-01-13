#include<stdio.h>
#include<stdlib.h>
struct avl{
	int data;
	struct avl* left;
	struct avl* right;
	int height;
};
struct avl *precedeser(struct avl *root)
{
	root=root->left;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}
struct avl *leftrot(struct avl *root)
{
	 // printf("I am here 4/n");
	struct avl *temp=root->right;
	root->right=temp->left;
	temp->left=root;
	 // printf("I am here 5/n");
	root->height=max(Height(root->left),Height(root->right))+1;
	temp->height=max(Height(temp->left),Height(temp->right))+1;
	return temp;
}
struct avl *rightrot(struct avl *root)
{
	struct avl *temp=root->left;
	root->left=temp->right;
	temp->right=root;
	 // // printf("I am here 60/n");
	root->height=max(Height(root->left),Height(root->right))+1;
	temp->height=max(Height(temp->left),Height(temp->right))+1;
	return temp;
}
int Height(struct avl *root)
{
	if(root==NULL)
	return 0;
	else
	return root->height;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int balance(struct avl *root)
{
	return Height(root->left)-Height(root->right);
}
struct avl *newnode(struct avl *root,int data)
{
	struct avl *temp=(struct avl *)malloc(sizeof(struct avl));
	temp->data=data;
	temp->left=temp->right=NULL;
	temp->height=1;
	 // printf("I am here 3\n");
	return temp;
}
struct avl *insert(struct avl *root,int data)
{
	if(root==NULL)
	{
		 // printf("I am here 6\n");
		root=newnode(root,data);
		return root;
	}
	else if(data<root->data)
	{
		 // printf("I am here 7\n");
		root->left=insert(root->left,data);
	}
	else if(data>root->data)
	{
		 // printf("I am here 8\n");
		root->right=insert(root->right,data);
	}
	root->height=max(Height(root->left),Height(root->right))+1;
	 // printf("Height=%d",root->height);
	int Balance=balance(root);
	 // printf("balance=%d",Balance);
	if(Balance>1 && data<root->left->data)
	{
		 // printf("I am here 9\n");
		root=rightrot(root);
		return root;
	}
	else if(Balance<-1 && data>root->right->data)
	{
		 // printf("I am here 10\n");
		root=leftrot(root);
		return root;
	}
	else if(Balance<-1 && data<root->right->data)
	{
		 // printf("I am here 11\n");
		root->right=rightrot(root->right);
		return leftrot(root);
	}
	else if(Balance>1 && data>root->left->data)
	{
		 // printf("I am here 12\n");
		root->left=leftrot(root->left);
		return rightrot(root);
	}
	return root;
}
void preOrder(struct avl *root)
{
	 // printf("I am here 1\n");
    if( root!= NULL)
    {
         printf("%d ", root->data);
         // printf("I am here 2\n");
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct avl *delbst(struct avl *root)
{
	if(root->left==NULL && root->right==NULL)
	{
		root=NULL;
		return root;
	}
	else if(root->left==NULL && root->right!=NULL)
	{
		struct avl *temp=root->right;
		free(root);
		return temp;
	}
	else if(root->right==NULL && root->left!=NULL)
	{
		struct avl *temp=root->left;
		free(root);
		return temp;
	}
	else
	{
		struct avl *temp=precedeser(root);
		root->data=temp->data;
		temp=NULL;
		return root;
	}
}
struct avl *delet(struct avl *root,int data)
{
	if(root==NULL)
	return root;
	else if(data==root->data)
	{
		// printf("I am here 20\n");
		root=delbst(root);
	}
	else if(data<root->data)
	{
		// printf("I am here 21\n");
		root->left=delet(root->left,data);
		
	}
	else if(data>root->data)
	{
		// printf("I am here 22\n");
		root->right=delet(root->right,data);
	}
	// printf("root=%d\nHeight=%d\nHeight(root->left)=%d\n",root->data,Height(root),Height(root->left));
	root->height=max(Height(root->left),Height(root->right))+1;
	int Balance=balance(root);
	// printf("balance(root)=%d\n",balance(root));
	if(root->left!=NULL)
	{
		// printf("root(left)=%d\nroot(left-left)=%d\nroot(left-rght)=%d\nroot(main)=%d\n",root->left->data,root->left->left->data,root->left->right->data,root->left->left->left->data);
	// printf("balance(root->left)=%d\n",balance(root->left));
	// printf("Height(root->left->left)=%d\nHeight(root->left->right)=%d\n",Height(root->left->left),Height(root->left->right));
}
	if(Balance>1 && balance(root->left)>=0)
	{
		 // printf("I am here 9\n");
		root=rightrot(root);
		return root;
	}
	else if(Balance<-1 && balance(root->right)<=0)
	{
		 // printf("I am here 10\n");
		root=leftrot(root);
		return root;
	}
	else if(Balance<-1 && balance(root->right)>0)
	{
		 // printf("I am here 11\n");
		root->right=rightrot(root->right);
		return leftrot(root);
	}
	else if(Balance>1 && balance(root->left)<0)
	{
		 // printf("I am here 12\n");
		root->left=leftrot(root->left);
		return rightrot(root);
	}
	// printf("I am here 92\n");
	return root;
}
int main()
{
	int n;
	 printf("Enter the No of values: ");
	scanf("%d",&n);
	struct avl *root=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		int d;
		printf("Enter the Element: ");
		scanf("%d",&d);
		root=insert(root,d);
	}
	preOrder(root);
	//printf("Height(main)=%d\nand(%d)=%d\n",Height(root->left->left->left),root->left->left->data,Height(root->left->left));
	int d;
	printf("Enter the value u want to delete: ");
	scanf("%d",&d);
	root=delet(root,d);
	preOrder(root);
	return 0;
}
/*The rotation operations (left and right rotate) take constant 
time as only a few pointers are being changed there. Updating 
the height and getting the balance factor also takes constant 
time. So the time complexity of AVL insert remains same as BST 
insert which is O(h) where h is the height of the tree. Since 
AVL tree is balanced, the height is O(Logn). So time complexity
 of AVL insert is O(Logn).*/
