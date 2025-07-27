#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int a[],int l,int r)
{
    int p,i,j;
    p=a[l];
    i=l;
    j=r+1;
    do{
        do{
            count++;
            i=i+1;
        }while(a[i]<p);
        do{
            count++;
            j=j-1;
        }while(a[j]>p);
        swap(a,i,j);
    }while(i<j);
    swap(a,i,j);
    swap(a,l,j);
    return j;
}
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
}
int main()
{
    int *a;
    FILE *fp1,*fp2;
    srand(time(NULL));
    fp1=fopen("qnums.txt","w");
    fp2=fopen("qcount.txt","w");
    for(int iter=5;iter<=50;iter+=5)
    {
        a=(int*)malloc(iter*sizeof(int));
        if(a==NULL)
        {
            printf("no memory\n");
            exit(0);
        }
        //Best case
        count=0;
        fprintf(fp1,"Best case inputs: ");
        for(int i=0;i<iter;i++)
        {
            a[i]=10;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        quicksort(a,0,iter-1);
        fprintf(fp2,"%d %d ",iter,count);
        fprintf(fp1,"Sorted array is: ");
        for(int i=0;i<iter;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        //Average case
        count=0;
        fprintf(fp1,"Average case inputs: ");
        for(int i=0;i<iter;i++)
        {
            a[i]=rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        quicksort(a,0,iter-1);
        fprintf(fp2,"%d ",count);
        fprintf(fp1,"Sorted array is: ");
        for(int i=0;i<iter;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        //Worst case
        count=0;
        fprintf(fp1,"Worst case inputs: ");
        a[0]=rand()%10;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<iter;i++)
        {
            a[i]=a[i-1]+rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        quicksort(a,0,iter-1);
        fprintf(fp2,"%d\n",count);
        fprintf(fp1,"Sorted array is: ");
        for(int i=0;i<iter;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
    }
    fclose(fp1);
    fclose(fp2);
    free(a);
    return 0;
}