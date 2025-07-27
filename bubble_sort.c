#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int iter;
int bubble_sort(int a[])
{
    int temp=0,count=0,f=0;
    for(int i=0;i<iter-1;i++)
    {
        for(int j=0;j<iter-i-1;j++)
        {
            count++;
            if(a[j]>a[j+1])
            {
                f=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(f==0)
        break;
    }
    return count;
}
int main()
{
    int *a,count;
    FILE *fp1,*fp2;
    fp1=fopen("Numbs.txt","w");
    fp2=fopen("CountB.txt","w");
    srand(time(0));
    for(iter=5;iter<=50;iter+=5)
    {
        fprintf(fp1,"Iteration-%d\n",iter/5);
       a=(int*)malloc(iter*sizeof(int));
       if(a==NULL)
       {
        printf("No memory\n");
        exit(0);
       }
    //Best case
    a[0]=rand()%10;
    fprintf(fp1,"%d ",a[0]);
    for(int i=1;i<iter;i++)
    {
        a[i]=a[i-1]+4;
        fprintf(fp1,"%d ",a[i]);
    }
    fprintf(fp1,"\n");
    count=bubble_sort(a);
    fprintf(fp2,"%d %d ",iter,count);
    //Average case
    for(int i=0;i<iter;i++)
    {
        a[i]=rand()%100;
        fprintf(fp1,"%d ",a[i]);
    }
    fprintf(fp1,"\n");
    count=bubble_sort(a);
    fprintf(fp2,"%d ",count);
    //Worst case
     a[0]=rand()%1000;
    fprintf(fp1,"%d ",a[0]);
    for(int i=1;i<iter;i++)
    {
        a[i]=a[i-1]-10;
        fprintf(fp1,"%d ",a[i]);
    }
    fprintf(fp1,"\n");
    count=bubble_sort(a);
    fprintf(fp2,"%d\n",count);
    }
}