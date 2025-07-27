#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,count=0;
    FILE *fp;
    fp=fopen("gcd.txt","a");
    for(int iter=1;iter<6;iter++)
    {
        printf("Enter two numbers: ");
        scanf("%d%d",&a,&b);
        while(a!=b)
        {
            count++;
            if(a>b)
            {
                a-=b;
            }
            else{
                b-=a;
            }
        }
        fprintf(fp,"%d %d\n",iter,count);
    }
}