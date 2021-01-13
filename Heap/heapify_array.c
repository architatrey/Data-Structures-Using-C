#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *a;
	int capacity;
	int size;
}heap;
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
int parent(heap *root,int p)
{
	int pa=(p-1)/2;
	if(pa<0)
	return -1;
	return pa;
}
void buildheap(heap *,int *,int);
void percolatedown(heap *root,int pos);
heap *create(heap *root,int capacity);
int main()
{
	int n;
	printf("Enter theno of elements in the array: ");
	scanf("%d",&n);
	int i,*a;
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	heap *root=create(root,n);
	buildheap(root,a,n);
	for(i=0;i<root->size;i++)
	printf("%d\n",root->a[i]);
	return 0;
}
void buildheap(heap *root,int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		root->a[i]=a[i];
		root->size++;
	}
	for(i=parent(root,root->size-1);i>=0;i--)
	{
		percolatedown(root,i);
	}
}
heap *create(heap *root,int capacity)
{
		root=(heap *)malloc(sizeof(heap));
		root->size=0;
		root->capacity=capacity;
		root->a=(int *)malloc(capacity*sizeof(int));
		return root;
}
void percolatedown(heap *root,int pos)
{
	int r=right(root,pos);
	int l=left(root,pos);
	if(l==-1 && r== -1)
	return;
	int max;
	if(l!=-1 && root->a[pos]<root->a[l])
	{
		max=l;
	}
	else
	max=pos;
	if(r!=-1 && root->a[max]<root->a[r])
	max=r;
	if(max!=pos)
	{
		int temp=root->a[pos];
		root->a[pos]=root->a[max];
		root->a[max]=temp;
		percolatedown(root,max);
	}
}
