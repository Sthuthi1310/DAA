#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int iter;
int selection_sort(int a[])
{
    int temp=0,min,count=0,swap=0;
    for(int i=0;i<iter-1;i++)
    {
        min=i;
        for(int j=i+1;j<iter;j++)
        {
            count++;
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    return count;
}
int main()
{
    int *a,count;
    FILE *fp1,*fp2;
    fp1=fopen("NumS.txt","w");
    fp2=fopen("CounS.txt","w");
    for(iter=5;iter<=50;iter+=5)
    {
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
    count=selection_sort(a);
    fprintf(fp2,"%d %d ",iter,count);
    //Average case
    for(int i=0;i<iter;i++)
    {
        a[i]=rand()%100;
        fprintf(fp1,"%d ",a[i]);
    }
    fprintf(fp1,"\n");
    count=selection_sort(a);
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
    count=selection_sort(a);
    fprintf(fp2,"%d\n",count);
    }
}
