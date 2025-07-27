#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int DistributeCount(int a[],int n,int u,int l)
{
    int *D,S[n],count=0;
    int s=u-l+1;
    D=(int*)malloc(s*sizeof(int));
    if(D==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    for(int i=0;i<s;i++)
    {
        D[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        D[a[i]-l]=D[a[i]-l]+1;
    }
    for(int i=1;i<s;i++)
    {
        D[i]=D[i-1]+D[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        count++;
        int j=a[i]-l;
        S[D[j]-1]=a[i];
        D[j]=D[j]-1;
    }
    return count;
}
int main()
{
    int *a,n,Count,u,l;
    FILE *fp1=fopen("dnum.txt","w");
    FILE *fp2=fopen("dcount.txt","w");
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
    l=rand()%100;
    u=l+rand()%10;
    fprintf(fp1,"u=%d \nl=%d\n",u,l);
    for(int i=0;i<n;i++)
    {
        a[i] = rand() % (u - l + 1) + l;
        fprintf(fp1,"%d ",a[i]);
    }
    
    fprintf(fp1,"\n");
    Count=DistributeCount(a,n,u,l);
    fprintf(fp2,"%d %d\n",n,Count);
    }
    
}