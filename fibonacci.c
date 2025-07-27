#include<stdio.h>
#include<stdlib.h>
int Count=0;
int fib(int n)
{
    Count++;
    if(n==0||n==1)
    return n;
    else
    fib(n-1)+fib(n-2);
    return Count;
}
int main()
{
    int n,Count;
    FILE *fp;
    fp=fopen("countfib.txt","w");
    for(int i=1;i<=10;i++)
    {   
        printf("Enter the value of n: ");
        scanf("%d",&n);
        Count=fib(n);
        fprintf(fp,"%d %d\n",n,Count);
    }
}