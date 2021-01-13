#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *a;
	int capacity;
	int size;
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
void insert(int data,heap *root);
void del(heap *root);
void percolatedown(heap *root,int pos);
void percolateup(heap *,int pos);
int main()
{
	int n,*a;
	printf("Enter the no of element: ");
	scanf("%d",&n);
	heap *root=create(root,n);
	int i;
	for(i=0;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		insert(d,root);
	}
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i]=root->a[0];
		del(root);
	}
	free(root->a);
	free(root);
	for(i=0;i<n;i++)
	{
		printf("a[%d]=%d\n",i,a[i]);
	}
	return 0;
}
heap *create(heap *root,int capacity)
{
		root=(heap *)malloc(sizeof(heap));
		root->size=0;
		root->capacity=capacity;
		root->a=(int *)malloc(capacity*sizeof(int));
		return root;
}
void insert(int data,heap *root)
{
	if(root->size>=root->capacity)
	{
		printf("Heap Overflow......");
		return;
	}
	root->a[root->size]=data;
	percolateup(root,root->size);
	root->size++;
}
void del(heap *root)
{
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
	if(l!=-1 && root->a[pos]>root->a[l])
	{
		max=l;
	}
	else
	max=pos;
	if(r!=-1 && root->a[max]>root->a[r])
	max=r;
	if(max!=pos)
	{
		int temp=root->a[pos];
		root->a[pos]=root->a[max];
		root->a[max]=temp;
		percolatedown(root,max);
	}
}
void percolateup(heap *root,int pos)
{
	int size=root->size;
	int p=parent(root,pos);
	int child=root->a[pos];
	if(root->a[p]>child)
	{
		root->a[pos]=root->a[p];
		root->a[p]=child;
		percolateup(root,p);
	}
}
