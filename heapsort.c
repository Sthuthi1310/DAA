#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int count1=0;
int heap(int H[],int n)
{
    int parent,child,P;
    bool heap=false;
    for(int i=n/2-1;i>=0;i--)
    {
        parent=i;
        P=H[parent];
        heap=false;
        while(!heap && 2*parent+1<n)
        {
            child=2*parent+1;
            if (child + 1 < n && H[child+1] > H[child]) {
            child = child + 1;
        }

            count1++;
            if(P>=H[child])
            {
                heap=true;
            }
            else
            {
                H[parent]=H[child];
                parent=child;
            }
        }
        H[parent]=P;
    }
    return count1;
}
int delheap(int H[],int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    heap(H,n);
    int root,lastc;
    int i=n-1;
    while(i>0)
    {
        count1++;
        int temp = H[0];
        H[0] = H[i];
        H[i] = temp;
        i=i-1;
        heap(H,i);
    }
    return count1;
} 
int main()
{
    int *H, n,count;
    FILE *fp1, *fp2;
    fp1 = fopen("hnums.txt", "w");
    fp2 = fopen("hcount.txt", "w");
    if(fp1 == NULL || fp2 == NULL) {
    printf("File open failed\n");
    exit(1);
    }
    srand(time(NULL));
    for(n=10;n<=100;n+=10)
    {
         H=(int*)malloc(n*sizeof(int));
    if(H==NULL)
    {
        printf("No memoryy\n");
        exit(0);
    }
    //Best case 
    count1=0;
    fprintf(fp1,"Best case input: ");
    H[0]=rand()%1000;
    fprintf(fp1,"%d ",H[0]);
    for(int i=1;i<n;i++)
    {
        H[i]=H[i-1]-50;
        fprintf(fp1,"%d ",H[i]);
    }
    fprintf(fp1,"\n");
    count=delheap(H,n);
    fprintf(fp2,"%d %d ",n,count);
    //Average case 
    count1=0;
    fprintf(fp1,"Average case input: ");
    for(int i=0;i<n;i++)
    {
        H[i]=rand()%100;
        fprintf(fp1,"%d ",H[i]);
    }
    fprintf(fp1,"\n");
    count=delheap(H,n);
    fprintf(fp2,"%d ",count);
    //Worst case 
    count1=0;
    fprintf(fp1,"Worst case input: ");
    H[0]=rand()%100;
    fprintf(fp1,"%d ",H[0]);
    for(int i=1;i<n;i++)
    {
        H[i]=H[i-1]+5;
        fprintf(fp1,"%d ",H[i]);
    }
    fprintf(fp1,"\n");
    count=delheap(H,n);
    fprintf(fp2,"%d\n",count);
    }
}