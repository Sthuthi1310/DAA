#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int Sum(int n)
{
    count++;
    if(n==1)
    {
        return 1;
    }
    else{
         (Sum(n-1)+(n*n*n));
    }
    return count;
}
int main()
{
    int n,sum=0;
    FILE *fp,*fp1;
    srand(time(NULL));
    
    for(int i=1;i<=10;i++)
    {
        fp=fopen("sum.txt","w");
        fp1=fopen("num.txt","w");
        n=rand()%10;
        fprintf(fp1,"%d\n",n);
         sum=Sum(n);
        fprintf(fp,"%d %d\n",i,sum);
    }
} 