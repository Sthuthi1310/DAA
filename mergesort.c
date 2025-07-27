#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int merge(int b[],int c[],int a[],int p,int q)
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        count++;
        if(b[i]<=c[j])
        {
            a[k]=b[i++];
        }
        else
        a[k]=c[j++];
        k++;
    }
    if(i==p)
    {
        while(j<q&&k<(p+q))
        {
        a[k++]=c[j++];
        }
    }
    else{
         while(i<p&&k<(p+q))
        {
        a[k++]=b[i++];
        }
    }
    return count;
}
int mergesort(int a[],int n)
{
    int *b,*c,p,q;
    p=n/2;
    q=n-p;
    b=(int*)malloc(p*sizeof(int));
    c=(int*)malloc(q*sizeof(int));
    if(b==NULL||c==NULL)
    exit(0);
    if(n<=1)
    return n;
    else
    {
        for(int i=0;i<p;i++)
        {
            b[i]=a[i];
        }
        for(int i=0;i<q;i++)
        {
            c[i]=a[p+i];
        }
        mergesort(b,p);
        mergesort(c,q);
        merge(b,c,a,p,q);
    }
    return count;
}

void worstcase(int a[],int beg,int end)
{
 if((end-beg)<=1)
 return;
 int mid=(beg+end)/2;
 int size=end-beg;
 int *t=(int*)malloc(size*sizeof(int));
 if(t==NULL)
 {
    printf("no memoy\n");
    exit(0);
 }   
 for(int i=0;i<size;i++)
 {
    t[i]=a[beg+i];
 }
 worstcase(t,0,(size/2));
 worstcase(t+(size/2),0,size-(size/2));
 for(int i=0;i<size/2;i++)
 {
    a[beg+2*i]=t[i];
 }
 for(int i=0;i<(size-size/2);i++)
 {
    a[beg+2*i+1]=t[(size/2)+i];
 }

}
int main()
{
    int *a;
    FILE *fp1,*fp2,*fp3;
    srand(time(NULL));
    fp1=fopen("mnums.txt","w");
    fp2=fopen("mcount.txt","w");
    fp3=fopen("msort.txt","w");
    for(int iter=10;iter<=100;iter+=10)
    {
        count=0;
        a=(int*)malloc(iter*sizeof(int));
        if(a==NULL)
        {
            printf("no memory\n");
            exit(0);
        }
        //Best case
        a[0]=rand()%10;
        fprintf(fp1,"%d ",a[0]);
        for(int i=1;i<iter;i++)
        {
            a[i]=a[i-1]+10;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        count=mergesort(a,iter);
        fprintf(fp2,"%d %d ",iter,count);
        fprintf(fp3,"Best case");
        for(int i=0;i<iter;i++)
        fprintf(fp3,"%d ",a[i]);
        fprintf(fp3,"\n");
        count=0;
        //Average case
        for(int i=0;i<iter;i++)
        {
            a[i]=rand()%100;
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        count=mergesort(a,iter);
        fprintf(fp2,"%d ",count);
        fprintf(fp3,"Average case");
        for(int i=0;i<iter;i++)
        fprintf(fp3,"%d ",a[i]);
        fprintf(fp3,"\n");
        count=0;
        //Worst case
        a[0]=rand()%100;
        for(int i=1;i<iter;i++)
        {
            a[i]=a[i-1]+rand()%10;
        }
        worstcase(a,0,iter);
        for(int i=0;i<iter;i++)
        {
            fprintf(fp1,"%d ",a[i]);
        }
        fprintf(fp1,"\n");
        count=mergesort(a,iter);
        fprintf(fp2,"%d\n",count);
        fprintf(fp3,"Worst case");
        for(int i=0;i<iter;i++)
        fprintf(fp3,"%d ",a[i]);
        fprintf(fp3,"\n");
    }
}