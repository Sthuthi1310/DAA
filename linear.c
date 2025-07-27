#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,n,i,key,f=0;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No memory is allocated\n");
        exit(0);
    }
    printf("ENter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    printf("Enter the key value: ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(*(a+i)==key)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("Key found\n");
    }
    else{
        printf("Key not found\n");
    }
}