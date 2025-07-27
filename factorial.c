#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int factorial(int n,int count)
{
    count++;
    if(n<2)
    return 1;
    else
    {
        n*factorial(n-1,count);
    }
    return count;
    count=0;
}
int main()
{
    int n;
    FILE *fp;
    srand(time(NULL));
    fp=fopen("CountFa.txt","w");
    for(int i=1;i<=10;i++)
    {
    printf("Enter the number whose factorial has to be found: ");
    scanf("%d",&n);
    count=factorial(n,count);
    fprintf(fp,"%d %d\n",n,count);
    }
}
