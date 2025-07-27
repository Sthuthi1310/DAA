#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int CompareCountSort(int *a,int n)
{
    int count[n];
    int S[n],Count=0;
    for(int i=0;i<n;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        //Count++;
        for(int j=i+1;j<n;j++)
        {
            Count++;
            if(a[i]<a[j])
            {
                count[j]=count[j]+1;
            }
            else
            {
                count[i]=count[i]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        S[count[i]]=a[i];
    }
    return Count;
}
int main()
{
    int *a,n,Count;
    FILE *fp1=fopen("cnum.txt","w");
    FILE *fp2=fopen("ccount.txt","w");
    srand(time(NULL));
    for(int n=10;n<=100;n+=10)
    {
         a=(int*)malloc(n*sizeof(int));
         if(a==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    fprintf(fp1,"Iteration %d : \n",n/10);
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
        fprintf(fp1,"%d ",a[i]);
    }
    fprintf(fp1,"\n");
    Count=CompareCountSort(a,n);
    fprintf(fp2,"%d %d\n",n,Count);
    }
    
}