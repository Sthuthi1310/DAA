#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int toh(int n,char A,char B,char C)
{
    if(n==1)
    {
        count++;
        return 1;
    }
    else{
        toh(n-1,A,C,B);
        count++;
        toh(n-1,B,A,C);
    }
    return count;
}
int main()
{
    int n;
    char A,B,C;
    FILE *fp;
    srand(time(0));
    fp=fopen("CountTOH.txt","w");
    for(int i=1;i<=10;i++)
    {
        printf("Enter the disk nums");
        scanf("%d",&n);
         count=toh(n,'A','B','C');
        fprintf(fp,"%d %d\n",n,count);
    }
}