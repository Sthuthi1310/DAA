#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,count1=0,count2=0,count3=0,rem,min;
    FILE *fp;
    fp=fopen("gcd5.txt","w");
    for(int iter=1;iter<=10;iter++)
    {
        count1=0,count2=0,count3=0;
        printf("Enter any two numbers: ");
        scanf("%d%d",&a,&b);
        int p=a,q=b;
        int x=a,y=b;
        //Method 1: Euclid's Algorithm
        while(b!=0)
        {
            count1++;
            rem=a%b;
            a=b;
            b=rem;
        }
        //Method 2:Consecutive Interger Method
        min=(p<q)?p:q;
        while(min!=0)
        {
            count2++;
            if(p%min==0 && q%min==0)
            {
                break;
            } 
            min--;
        }
        //Method 3: Modified Euclid's Algorithm
        while(x!=y)
        {
            count3++;
            if(x>y)
            {
                x-=y;
            }
            else
            y-=x;
        }
        fprintf(fp,"%d %d %d %d \n",iter,count1,count2,count3);
    }
}