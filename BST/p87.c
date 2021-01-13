#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
	struct tree *nextRight;
};
typedef struct queue
{
	struct tree *data;
	struct queue *next;
};
struct tree *samelevel(struct tree *);
void print(struct tree *);
void insertq(struct tree *);
void del();
int peek();
queue *end=NULL,*head=NULL;
struct tree *insert(struct tree* node,int data);
struct tree *newnode(int data);
struct tree *removebw(struct tree *root,int min,int max);
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
	root=samelevel(root);
	print(root);
	return 0;
}
struct tree *samelevel(struct tree *root)
{
	if(root==NULL)
	return root;
	insertq(root);
	insertq(NULL);
	while(head!=end)
	{
		struct tree *p=head->data;
		del();
		if(p!=NULL)
		{
			p->nextRight=head->data;
			if(p->left!=NULL)
			{
				insertq(p->left);
			}
			if(p->right!=NULL)
			{
				insertq(p->right);
			}
		}
		else if(head!=end)
		{
			insertq(NULL);
		}
	}
		return root;
	}
void insertq(struct tree *a)
{
	queue *temp=(queue*)malloc(sizeof(queue*));
	if(temp==NULL)
	{
		printf("Overflow");
		return;
	}
	if(head==NULL)
	{
		temp->data=a;
		temp->next=NULL;
		head=temp;
		end=temp;
		return;
	}
	temp->data=a;
	temp->next=NULL;
	end->next=temp;
	end=temp;
}
void del()
{
	if(head==NULL)
	{
		printf("\nNot enough elements");
		return;
	}
	queue *temp;
	temp=head;
	head=temp->next;
	free(temp);
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
	temp->nextRight=NULL;
	temp->left=temp->right=NULL;
	return temp;
}
void print(struct tree *root)
{
	if(root==NULL)
	return;
	struct tree *p=root;
	while(root!=NULL)
	{
		printf("%d\t",root->data);
		root=root->nextRight;
		if(root==NULL)
		printf("-1\t");
	}
	printf("\n");
	if(p->left)
	print(p->left);
	else
	print(p->right);
}
