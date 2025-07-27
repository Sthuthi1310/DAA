#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,rem,count=0,min,gcd;
    FILE *fp;
    fp=fopen("gcd4.txt","w");
    for(int iter=1;iter<=5;iter++)
    {
        printf("Enter two numbers: ");
        scanf("%d%d",&a,&b);
        int x=a,y=b;
        int p=a,q=b;
        while(b!=0)
        {
            count++;
            rem=a%b;
            a=b;
            b=rem;
        }
        fprintf(fp,"%d %d\n",iter,count);
        count=0;
        while(x!=y)
        {
            count++;
            if(x>y)
            {
                x-=y;
            }
            else{
                y-=x;
            }
        }
        fprintf(fp,"%d %d\n",iter,count);
        count=0;
        min = (p < q) ? p : q;

        while (min != 0)
        {
            count++;
            if (p % min == 0 && q % min == 0)
            {
                gcd = min;
                break;
            }
            min--;
        }

            fprintf(fp,"%d %d\n",iter,count);
    }
}