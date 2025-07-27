#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 5
#define y 50
#define z 5
int main()
{
    int *a,key,f=0,count=0;
    FILE *fp1,*fp2;
    fp1=fopen("NumberB.txt","a");
    srand(time(NULL));
    for(int iter=x;iter<=y;iter+=z)
    {
        count=0;
        a=(int*)malloc(iter*sizeof(int));
        if(a==NULL)
        {
            printf("No memory\n");
            exit(0);
        }
        for(int i=0;i<iter;i++)
        {
            *(a+i)=(rand()%90)+10;
            fprintf(fp1,"%d\n",*(a+i)); 
        }  
        fp2=fopen("CountB.txt","a");
        int low=0;
        int high=iter-1;
        int mid;
        key=*(a+(iter)/2-1);
        while(low<=high)
        {
            count++;
            mid=(low+high)/2;
            if(*(a+mid)==key)
            {
                f=1;
                break;
            }
            if(key<*(a+mid))
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        fprintf(fp2,"%d %d\n",iter,count);
    }
}