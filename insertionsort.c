#include<stdio.h>
#include<stdlib.h>
int insertion_sort(int a[],int n)
{
    int i=1,key,j;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    return *a;
}
int main()
{
    int *a,n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    printf("Array elements in unsorted manner ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n");
    insertion_sort(a,n);
    printf("Array elements in sorted order is : ");
    for(int i=0;i<n;i++)
    printf("%d ",*(a+i));
}