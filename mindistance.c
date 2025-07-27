#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,n,len=0,dist=0;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    printf("Enter the array elements in sorted order: ");
    for(int i=0;i<n;i++)
    scanf("%d",a+i);
    len=a[n-1]-a[0];
    for(int i=0;i<n-1;i++)
    {
        dist=a[i+1]-a[i];
        if(dist<len)
        len=dist;
    }
    printf("min distance is %d\n",len);
}