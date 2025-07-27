#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,f=0,count=0;
    FILE *fp;
    fp=fopen("prime.txt","a");
    for(int iter=1;iter<=5;iter++)
    {
        printf("Enter the number: ");
        scanf("%d",&n);
        if(n<1)
        {
            printf("Neither prime nor composite\n");
            return 0;
        }
        for(int i=2;i<n;i++)
        {
            count++;
            if(n%i==0)
            {
                f=1;
                break;
            }
            fprintf(fp,"%d %d\n",iter,count);
        }
}
}