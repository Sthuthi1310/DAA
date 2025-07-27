#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,count=0,min,rem,gcd;
    FILE *fp;
    fp=fopen("gcd.txt","a");
    for(int iter=1;iter<6;iter++)
    {
        printf("Enter two numbers: ");
        scanf("%d%d",&a,&b);
        min = (a < b) ? a : b;

        while (min != 0)
        {
            count++;
            if (a % min == 0 && b % min == 0)
            {
                gcd = min;
                break;
            }
            min--;
        }

            fprintf(fp,"%d %d\n",iter,count);
        }
    }