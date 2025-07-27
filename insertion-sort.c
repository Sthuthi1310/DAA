#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int insertion_sort(int a[],int n)
{
    int i=1,key,j;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j >= 0 && a[j] > key) 
        {
            count++;
            a[j + 1] = a[j];
            j--;
        }
        if(j>=0)//j>=0 and a[j]!>key so j>=0 comparisions should be computed
        count++;
        a[j+1]=key;
    }
    return count;
}
int main()
{
    int *a,n;
    FILE* fp1,*fp2;
    fp1=fopen("inum.txt","w");
    fp2=fopen("icount.txt","w");
    srand(time(NULL));
    for(n=10;n<=100;n+=10)
    {
        a=(int*)malloc(n*sizeof(int));
        if(a==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        //Best case
        count=0;
        fprintf(fp1,"Best case input : ");
        a[0]=rand()%10;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+rand()%10;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        insertion_sort(a,n);
        fprintf(fp2,"%d %d ",n,count);
        //Average case
        fprintf(fp1,"Average case input : ");
        for(int i=0;i<n;i++)
        {
            a[i]=rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        count=0;
        insertion_sort(a,n);
        fprintf(fp2,"%d ",count);
        count=0;
        //Worst case
        fprintf(fp1,"Worst case input : ");
        a[0]=rand()%1000;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]-rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        insertion_sort(a,n);
        fprintf(fp2,"%d\n",count);
    }
    
}