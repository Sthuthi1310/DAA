#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,f=0,count2=0;
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
            count2++;
            if(n%i==0)
            {
                f=1;
                break;
            }
        }
        fprintf(fp,"%d  %d\n",iter,count2);
    }
}