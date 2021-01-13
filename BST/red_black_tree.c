#include<stdio.h>
#include<stdlib.h>
struct redblack{
	int data;
	struct redblack* left;
	struct redblack* right;
	struct redblack* parent;
	enum {red,black} color;
};
struct redblack *root,*sentinal;
void rightrot(struct redblack *node)
{
	if(node==NULL)
	return ;
	struct redblack* temp=node->parent;
	if(temp==root)
	{
		node->parent=sentinal;
		temp->parent=node;
		temp->left=node->right;
		node->right=temp;
		//printf("0\n");
		root=node;
		return;
	}
	if(temp==temp->parent->left)
	{
		node->parent=temp->parent;
		temp->parent->left=node;
		temp->left=node->right;
		node->right=temp;
		temp->parent=node;
		//printf("I am here 14\n");
	}
	else{
		temp->parent->right=node;
		node->parent=temp->parent;
		temp->left=node->right;
		node->right=temp;
		temp->parent=node;
		//printf("I am here 15\n");
	}
}
void leftrot(struct redblack *node)
{
	if(node==NULL)
	return;
	struct redblack *temp=node->parent;
	if(temp==root)
	{
		node->parent=sentinal;
		temp->right=node->left;
		node->left=temp;
    	//printf("I am here 21\n");
    	root=node;
    	temp->parent=node;
    	//printf("temp %d\npare=%d\n",temp->color,node->color);
    	return;
	}
    if(temp->parent->left==temp)
    {
    	temp->parent->left=node;
    	node->parent=temp->parent;
    	temp->right=node->left;
    	node->left=temp;
    	temp->parent=node;
    	//printf("I am here 12\n");
	}
	else if(temp->parent->right==temp)
	{
		//printf("1.........\n");
		temp->parent->right=node;
		node->parent=temp->parent;
    	temp->right=node->left;
    	node->left=temp;
    	temp->parent=node;
    	//printf("I am here 13\n");
	}
	return;
}
void isbalance(struct redblack* ptr)
{
	struct redblack* temp;
	while(ptr->parent!=NULL && ptr->parent->color==red)
	{
		struct redblack* gp=ptr->parent->parent;
		if(gp->left==ptr->parent)
		{
			//printf("I am here 1\n");
			struct redblack* uncle=gp->right;
			if(uncle->color==red)
			{
				uncle->color=black;
				ptr->parent->color=black;
				gp->color=red;
				//printf("I am h5ere 2\n");
				ptr=gp;
			}
			else if(uncle->color==black)
			{
				//printf("I am here 3\n");
				if(ptr==ptr->parent->left)
				{
					ptr->parent->color=black;
					gp->color=red;
					rightrot(ptr->parent);
					ptr=ptr->parent->parent;
					//printf("I am here 4\n");
				}
				else
				{
					leftrot(ptr);
					ptr->color=black;
					ptr->parent->color=red;
					rightrot(ptr);
					ptr=ptr->parent->parent;
					//printf("I am here 5\n");
				}
			}
		}
		else
		{
			struct redblack* uncle=gp->left;
			if(uncle->color==red)
			{
				uncle->color=black;
				ptr->parent->color=black;
				gp->color=red;
				ptr=gp;
				//printf("I am here 6\n");
			}
			else if(uncle->color==black)
			{
				//printf("I am here 7\n");
				if(ptr==ptr->parent->right)
				{
					ptr->parent->color=black;
					gp->color=red;
					leftrot(ptr->parent);
					ptr=ptr->parent->parent;
					//printf("I am here 8\n");
				}
				else
				{
					rightrot(ptr);
					ptr->color=black;
					ptr->parent->color=red;
					leftrot(ptr);
					ptr=ptr->parent->parent;
					//printf("I am here 9\n");
				}
			}
		}
	}
	//printf("I am here 10\n");
	root->color=black;
}
void insert(int data)
{
	struct redblack* temp,*ptr=sentinal;
	temp=root;
	while(temp!=sentinal)
	{
		//printf("I am here 16\n");
		ptr=temp;
		if(data<temp->data)
		temp=temp->left;
		else if(data>temp->data)
		temp=temp->right;
		else
		{
		printf("duplicate\n");
		return;
	}
	}
	struct redblack* temp2=(struct redblack*)malloc(sizeof(struct redblack));
	temp2->data=data;
	temp2->left=temp2->right=sentinal;
	temp2->parent=ptr;
	temp2->color=red;
	//printf("I am here 17\n");
	if(temp==ptr)
	root=temp2;
	else if(data<ptr->data)
	ptr->left=temp2;
	else if(data>ptr->data)
	ptr->right=temp2;
	//printf("I am here 18\n");
	//printf("%d %d\n",temp2->parent->data,temp2->data);
	isbalance(temp2);
}
void inorder(struct redblack *node)
{
	if(node==sentinal)
	return;
	inorder(node->left);
	printf("%d\t",node->data);
	if(node->color==red)
	printf("red\n");
	else if(node->color==black)
	printf("black\n");
	inorder(node->right);
}
struct redblack* find(struct redblack* ptr,int data)
{
	if(ptr==NULL)
	{
		return NULL;
	}
	if(ptr->data==data)
	return ptr;
	while(ptr!=sentinal || ptr->data!=data)
	{
		if(data<ptr->data)
		ptr=ptr->left;
		else if(data>ptr->data)
		ptr=ptr->right;
		else
		return ptr;
	}
	return ptr;
}
struct redblack* suces(struct redblack* ptr)
{
	ptr=ptr->right;
	while(ptr!=sentinal)
	{
		ptr=ptr->left;
	}
	return ptr;
}
void del(int data)
{
	struct redblack* ptr=find(root,data),*sucessor;
	if(ptr==NULL && ptr==sentinal)
	{
		printf("Not present ");
		return;
	}
	if(ptr->left!=sentinal || ptr->right!=sentinal)
	{
		sucessor=suces(ptr);
		ptr->data=sucessor->data;
		ptr=sucessor;
	}
	if(ptr->left!=NULL)
	child=ptr->left;
	else
	child=ptr->right;
	if(ptr->parent==setinal)
    child=root;
    else if(ptr==ptr->parent->left)
    {
    ptr->parent->left=child;
    child->parent=ptr->parent;
    }
    else if(ptr==ptr->parent->right)
    {
    	ptr->parent->right=child;
    	child->parent=ptr->parent;
	}
	if(child==root)
	{
		child->color=black;
	}
	if(ptr->color==black)
	{
		if(child!=sentinal)
		child->color=black;
		else
		bal_del(child);
	}
}
void bal_del(struct redblack *ptr)
{
	struct redblack *sib;
	while(ptr!=root)
	{
		if(ptr==ptr->parent->left)
		{
			sib=ptr->parent->right;
			if(sib->color==red)
			{
				sib->color=black;
				ptr->parent->color=red;
				rotleft(ptr->parent);
				sib=ptr->parent->right;
			}
			if(sib->left->color==black && sib->right->color==black)
			{
				sib->color=red;
				if(ptr->parent->color==red)
				{
					ptr->parent->color=black;
					return;
				}
				else
				{
					ptr=ptr->parent;
				}
			}
			else
			{
				if(sib->right->color==black)
				{
					sib->left->color=black;
				}
			}
		}
	}
}
int main()
{
	sentinal=(struct redblack *)malloc(sizeof(struct redblack));
	sentinal->color=black;
	sentinal->data=-1;
	sentinal->left=sentinal->parent=sentinal->right=NULL;
	root=sentinal;
	printf("enter the no of elements: ");
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int d;
		printf("entre the Element: ");
		scanf("%d",&d);
		insert(d);
	}
	inorder(root);
	return 0;
}
