#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int count1=0,count2=0;
void heap(int H[],int n)
{
    int parent,child,P;
    bool heap=false;
    for(int i=n/2-1;i>=0;i--)
    {
        parent=i;
        P=H[parent];
        heap=false;
        while(!heap && 2*parent+1<=n)
        {
            child=2*parent+1;
            if(child<n)
            {
                count1++;
                if(H[child+1]>H[child])
                {
                    child=child+1;
                }
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
}
void delheap(int H[],int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    heap(H,n);
    printf("The heap is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", H[i]);
    }
    int root,lastc;
    int i=n-1;
    while(i>0)
    {
        count2++;
        int temp = H[0];
        H[0] = H[i];
        H[i] = temp;
        i=i-1;
        heap(H,i);
    }
} 
int main()
{
    int *H,n;
    FILE *fp1,*fp2;
    fp1=fopen("hnums.txt","w");
    fp2=fopen("hcount.txt","w");
    srand(time(NULL));
    //printf("Enter the size of the heap to be formed: ");
    //scanf("%d",&n);
    for(n=10;n<=100;n+=10)
    {
         H=(int*)malloc(n*sizeof(int));
    if(H==NULL)
    {
        printf("No memoryy\n");
        exit(0);
    }
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",H+i);
    delheap(H,n);
    printf("The sorted heap is : ");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",H[i]);
    }
    }
}