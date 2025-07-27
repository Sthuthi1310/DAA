#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,f=0,count1=0;
    FILE *fp;
    fp=fopen("prime.txt","a");
    for(int iter=1;iter<=5;iter++)
    {
        printf("Enter the number: ");
        scanf("%d",&n);
        if(n<=1)
        {
            printf("Neither prime nor consonent\n");
            return 0;
        }
        for(int i=2;i<=sqrt(n);i++)
        {
            count1++;
            if(n%i==0)
            {
                f==1;
            }
        }
        fprintf(fp,"%d %d\n",iter,count1);
    }

}