#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,f=0,count=0;
    FILE *fp;
    fp=fopen("prime.txt","a");
    for(int iter=1;iter<=5;iter++)
    {
        printf("ENter the number: ");
        scanf("%d",&n);
        if(n<=1)
        {
            printf("Number is neitheer prime nor consonent\n");
        }
        for(int i=2;i<=n;i++)
        {
            count++;
            if(n%i==0)
            {
                f=1;
                break;
            }
        }
        fprintf(fp,"%d  %d\n",iter,count);
        int count1=0;
        for(int i=2;i<n;i++)
        {
            count1++;
            if(n%i==0)
            {
                f=1;
                break;
            }
        }
        fprintf(fp,"%d %d \n",iter,count1);
        int count2=0;
        for(int i=2;i<(n/2);i++)
        {
            count2++;
            if(n%i==0)
            {
                f=1;
                break;
            }
        }
        fprintf(fp,"%d %d\n",iter,count2);
        int count3=0;
        for(int i=2;i<sqrt(n);i++)
        {
            count3++;
            if(n%i==0)
            {
                f=1;
                break;
            }
        }
        fprintf(fp,"%d %d\n",iter,count3);
    }
}