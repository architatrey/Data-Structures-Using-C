#include<stdio.h>
#include<stdlib.h>
struct leafnode{
	char ch;
	int freq;
	struct leafnode *left,*right;
};
typedef struct{
	int size;
	int capacity;
	struct leafnode **a;
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
struct leafnode *createleaf(char ch,int freq);
heap* create(heap *root,int capacity);
void buildheap(heap *root,char ch[],int freq[],int n);
void percolatedown(heap *root,int pos);
void percolateup(heap *root,int pos);
struct leafnode *buildtree(int freq[],char ch[],int size);
void printcodes(struct leafnode *root,int a[],int top);
void huffmantree(int a[],char ch [],int n);
void del(heap *);
int main()
{
	char arr[] = { 'v', 'w', 'x', 'y', 'z'};
    int freq[] = { 5, 36, 25, 58, 8};
    huffmantree(freq,arr,5);
	return 0;
}
struct leafnode *createleaf(char ch,int freq)
{
	// printf("I am here 1\n");
	struct leafnode *temp=(struct leafnode *)malloc(sizeof(struct leafnode));
	temp->ch=ch;
	temp->freq=freq;
	temp->left=temp->right=NULL;
	return temp;
}
heap* create(heap *root,int capacity)
{
	root=(heap *)malloc(sizeof(heap));
	root->size=0;
	root->capacity=capacity;
	// printf("I am here 2\n");
	root->a=(struct leafnode **)malloc(capacity*sizeof(struct leafnode*));
	return root;
}
void buildheap(heap *root,char ch[],int freq[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		root->a[i]=createleaf(ch[i],freq[i]);
		root->size++;
		// printf("I am here 3\n");
	}
	for(i=parent(root,root->size-1);i>=0;i--)
	{
		// printf("I am here 4\n");
		percolatedown(root,i);
	}
}
void percolatedown(heap *root,int pos)
{
	int r=right(root,pos);
	int l=left(root,pos);
	if(l==-1 && r== -1)
	return;
	int max;
	if(l!=-1 && root->a[pos]->freq>root->a[l]->freq)
	{
		max=l;
	}
	else
	max=pos;
	if(r!=-1 && root->a[max]->freq>root->a[r]->freq)
	max=r;
	if(max!=pos)
	{
		struct leafnode *temp=root->a[pos];
		root->a[pos]=root->a[max];
		root->a[max]=temp;
		percolatedown(root,max);
	}
}
struct leafnode *buildtree(int freq[],char ch[],int size)
{
	int i=25;
	heap *root=create(root,size);
	buildheap(root,ch,freq,size);
	while(root->size!=1)
	{
		struct leafnode *left=root->a[0];
		del(root);
		struct leafnode *right=root->a[0];
		del(root);
		struct leafnode *newleaf=createleaf('$',(left->freq+right->freq));
		newleaf->left=left;
		// printf("I am here 5\n");
		newleaf->right=right;
		// printf("left-%c right-%c\n",newleaf->left->ch,newleaf->right->ch);
		root->a[root->size]=newleaf;
		percolateup(root,root->size);
		root->size++;
		i--;
		if(i<=0)
		exit(0);
	}
	return root->a[0];
}
void del(heap *root)
{
	root->a[0]=root->a[root->size-1];
	root->size--;
	percolatedown(root,0);
	// printf("I am here 6\n");
}
void percolateup(heap *root,int pos)
{
	int size=root->size;
	int p=parent(root,pos);
	struct leafnode *child=root->a[pos];
	if(root->a[p]>child)
	{
		root->a[pos]=root->a[p];
		root->a[p]=child;
		percolateup(root,p);
	}
}
void printcodes(struct leafnode *root,int a[],int top)
{
	// printf("I am here 7\n");
    if(root->left!=NULL)
    {
    	a[top]=0;
    	printcodes(root->left,a,top+1);
	}
	if(root->right!=NULL)
	{
		a[top]=1;
		printcodes(root->right,a,top+1);
	}
	if(root->left==NULL && root->right==NULL)
	{
		printf("%c:\t",root->ch);
		int i;
		for(i=0;i<top;i++)
		printf("%d",a[i]);
	}
	printf("\n");
}
void huffmantree(int a[],char ch [],int n)
{
	// printf("I am here 9\n");
	struct leafnode *root=buildtree(a,ch,n);
	int ar[20];
	// printf("I am here 8\n");
	printcodes(root,ar,0);
}
