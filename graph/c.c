#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char str[62];
    scanf("%s",str);
    int a[26]={0},n,i;
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        int j=str[i];
        a[j-97]++;
    }
    int res;
    if(a[0]%2==0)
        res=0;
    else 
	res=1;
    for(i=1;i<26;i++)
    {
    	int res1;
    if(a[i]==0)
        continue;
    else if(a[i]%2==0)
	 {
	 	res1=0;
	 }
	 else
	res1=1;
	//printf("res1-%d,res=%d\n",res1,res);
        if(res1!=res)
        {
            printf("2");
            return 0;
        }
    }
    printf("%d",res);
    return 0;
}
