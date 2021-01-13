#include<stdio.h>
#include<stdlib.h>
#define load 20
struct node{
	int key;
	char employ[20];
};
struct list{
	struct node *record;
	struct list *link;
};
void create(int a[],int size)
{
	int i;
	for(i=0;i<size;i++)
	a[i]=0;
}
void insert(int a[],int size)
{
	struct node *temp1=(struct node *)malloc(sizeof(struct node));
	printf("enter the key and the name ");
	scanf("%d %s",&temp1->key,temp1->employ);
	printf("%d %s",temp1->key,temp1->employ);
	struct list *temp=(struct list *)malloc(sizeof(struct list));
//	printf("I am here 1\n");
	temp->record=temp1;
//	printf("I am here 2\n");
	int key=temp1->key%size;
//	printf("I am here 5\n");
	if(a[key]==0)
	{
		printf("I am here 3\n");
		a[key]=temp;
		temp->link=NULL;
		return;
	}
	temp->link=a[key];
//	printf("I am here 4\n");
	a[key]=temp;
}
void search(int a[],int d,int size)
{
	int key=d%size;
	struct list *temp=(struct list *)a[key];
	while(temp!=NULL)
	{
		if(temp->record->key==d)
		{
			printf("The key is found with name ");
			puts(temp->record->employ);
			return;
		}
		temp=temp->link;
	}
	printf("Key is not found\n");
}
int main()
{
	int n;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	int size=10;
	printf("%d",size);
	int a[size];
	create(a,size);
	int i;
	for(i=0;i<n;i++)
	{
		insert(a,size);
	}
	while(1)
	{
		int d;
		printf("enter the key to be searched: ");
		scanf("%d",&d);
		search(a,d,size);
	}
	return 0;
}
