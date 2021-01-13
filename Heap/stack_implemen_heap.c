#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int key;
	int value;
}data;
typedef struct{
	int capacity;
	int size;
	data **a;
}heap;
int parent(heap *root,int p)
{
	int pa=(p-1)/2;
	if(pa<0)
	return -1;
	return pa;
}
int right(heap *root,int p)
{
	int r=2*p+2;
	if(r>=root->size)
	return -1;
	return r;
}
int left(heap *root,int p)
{
	int l=(2*p+1);
	if(l>=root->size)
	return -1;
	return l;
}
heap *create(heap *root,int capacity);
void insert(heap *root,data *temp);
void del(heap *root);
void percolatedown(heap *root,int pos);
void percolateup(heap *root,int pos);
int main()
{
	int n,i=1,key=0;
	printf("Enter the max element in stack: ");
	scanf("%d",&n);
	heap* root=create(root,n);
	while(i)
	{
		printf("Enter the choice:\n1.To insert \n2.To delete\n3.To print the top element in stack\n");
		scanf("%d",&i);
		if(i==1)
		{
			int d;
			printf("Enter the element: ");
			scanf("%d",&d);
			data *temp=(data *)malloc(sizeof(data));
			temp->value=d;
			temp->key=key++;
			insert(root,temp);
		}
		else if(i==2)
		{
			del(root);
			key--;
		}
		else if(i==3)
		{
			printf("top=%d",root->a[0]->value);
		}
	}
	return 0;
}
heap *create(heap *root,int capacity)
{
	root=(heap *)malloc(sizeof(heap));
	root->capacity=capacity;
	root->size=0;
	root->a=(data **)malloc(capacity*sizeof(data*));
	return root;
}
void insert(heap *root,data *temp)
{
	if(root->size>=root->capacity)
	{
		printf("Heap Overflow......");
		return;
	}
	root->a[root->size]=temp;
	percolateup(root,root->size);
	root->size++;
}
void percolateup(heap *root,int pos)
{
	int size=root->size;
	int p=parent(root,pos);
	data *child=root->a[pos];
	if(root->a[p]->key<child->key)
	{
		root->a[pos]=root->a[p];
		root->a[p]=child;
		percolateup(root,p);
	}
}
void del(heap *root)
{
	free(root->a[0]);
	root->a[0]=root->a[root->size-1];
	root->size--;
	percolatedown(root,0);
}
void percolatedown(heap *root,int pos)
{
	int r=right(root,pos);
	int l=left(root,pos);
	if(l==-1 && r== -1)
	return;
	int max;
	if(l!=-1 && root->a[pos]->key<root->a[l]->key)
	{
		max=l;
	}
	else
	max=pos;
	if(r!=-1 && root->a[max]->key<root->a[r]->key)
	max=r;
	if(max!=pos)
	{
		data *temp=root->a[pos];
		root->a[pos]=root->a[max];
		root->a[max]=temp;
		percolatedown(root,max);
	}
}
