#include<stdio.h>
#include<stdlib.h>
struct tree{
	char ch;
	struct tree *left;
	struct tree *right;
};
struct stack
{
	struct tree *data;
	struct stack *link;
};
struct stack *head=NULL;
void insert(char ch);
void push(struct tree *);
void pop();
void inorder(struct tree *);
int main()
{
	char i='a';
	while(i!='0')
	{
		printf("Enter the no: ");
		scanf("%c%*c",&i);
		//printf("i am here 2");
		if(i!='0')
	    insert(i);
	    //printf("i am here 1");
	}
	struct tree *node=head->data;
	inorder(node);
	return 0;
}
void push(struct tree *data)
{
	struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
	temp->data=data;
	if(head==NULL)
	{
		head=temp;
		temp->link=NULL;
		return;
	}
	temp->link=head;
	head=temp;
}
void pop()
{
	struct stack *temp=head;
	if(head==NULL)
	{
		printf("Too few arguemants");
		return;
	}
	head=head->link;
	free(temp);
}
void insert(char ch)
{
	//printf("i am here 4");
	struct tree *temp=(struct tree *)malloc(sizeof(struct tree));
	temp->ch=ch;
	temp->left=NULL;
	temp->right=NULL;
	if((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
	{
	//	printf("i am here 3");
		push(temp);
		return;
	}
	else
	{
		temp->right=head->data;
		pop();
		temp->left=head->data;
		pop();
		push(temp);
	}
}
void inorder(struct tree *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%c",root->ch);
	inorder(root->right);
}
