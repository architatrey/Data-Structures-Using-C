#include<stdio.h>
void heapPermutation(int a[], int size, int n);
int z=0;
int main()
{
	int a[5]={1,2,3,4,5};
	heapPermutation(a,5,5);
	printf("%d",z);
}
void heapPermutation(int a[], int size, int n) 
{
    if (size == 1) 
    { 
        z++;
        return; 
    } 
  int i;
    for (i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
        if (size%2==1)
		{
			int temp=a[0];
        	a[0]=a[size-1];
        	a[size-1]=temp;
		 } 
        else
        {
        	int temp=a[i];
        	a[i]=a[size-1];
        	a[size-1]=temp;
		}
    } 
}
