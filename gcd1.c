#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,rem,count=0;
    FILE *fp;
    fp=fopen("gcd.txt","w");
    for(int iter=1;iter<=5;iter++)
    {
        printf("Enter two numbers: ");
        scanf("%d%d",&a,&b);
        while(b!=0)
        {
            count++;
            rem=a%b;
            a=b;
            b=rem;
        }
        fprintf(fp,"%d %d\n",iter,count);
    }
}