#include<stdio.h>
int noofbst(int n);
int main()
{
	printf("Enter the no of keys: ");
	int k;
	scanf("%d",&k);
	printf("No of BST: %d",noofbst(k));
	return 0;
}
int noofbst(int n)
{
	if(n==1 || n==0)
	return 1;
	if(n==2)
	return 2;
	if(n==3)
	return 5;
	int sum=0;
	if(n%2==0)
	{
		int i=0;
		for(i=0;i<=(n-2)/2;i++)
		{
			sum=sum+2*noofbst(n-i-1)*noofbst(i);
		}
		return sum; 
	}
	else
	{
		int i=0;
		for(i=0;i<=(n-3)/2;i++)
		{
			sum=sum+2*noofbst(n-i-1)*noofbst(i);
		}
		sum+=noofbst(n/2)*noofbst(n/2);
		return sum;
	}
}
