#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int largest(int a[],int l,int r)
{
    int maxl,maxr;
    if(l==r)
    return l;
    else{
        count++;
        maxl=largest(a,l,(l+r)/2);
        maxr=largest(a,((l+r)/2)+1,r);
        if(a[maxl]>=a[maxr])
        return maxl;
        else
        return maxr;
    }
}
int main()
{
    int *a;
    FILE *fp1,*fp2;
    fp1=fopen("lnum.txt","w");
    fp2=fopen("lcount.txt","w");
    srand(time(NULL));
    for(int iter=10;iter<=100;iter+=10)
    {
        a=(int*)malloc(iter*sizeof(int));
        if(a==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        //Best case
        a[0]=rand()%1000;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<iter;i++)
        {
            a[i]=a[i-1]-25;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        count=largest(a,0,iter-1);
        fprintf(fp2,"%d %d ",iter,count);
        //Average case
        count=0;
        for(int i=0;i<iter;i++)
        {
            a[i]=rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        count=largest(a,0,iter-1);
        fprintf(fp2,"%d ",count);
        //Worst case
        count=0;
        a[0]=rand()%100;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<iter;i++)
        {
            a[i]=a[i-1]+25;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        count=largest(a,0,iter-1);
        fprintf(fp2,"%d\n",count);
    }
}