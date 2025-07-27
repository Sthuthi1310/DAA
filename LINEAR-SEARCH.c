#include<stdio.h>
#include<stdlib.h>

#include<time.h>
#define x 10
#define y 100
#define z 10
int main()
{
    int *a,key,count=0;
    FILE *fp1,*fp2;
    srand(time(NULL));
    fp1=fopen("numbers.txt","w");
    fp2=fopen("count.txt","w");
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
      key=a[0];
      for(int i=0;i<iter;i++)
      {
        count++;
        if(*(a+i)==key)
        {
          break;
        }
      }
      fprintf(fp2,"%d %d ",iter,count);
      count=0;
      key=a[(iter-0)/2];
      for(int i=0;i<iter;i++)
      {
        count++;
        if(*(a+i)==key)
        {
          break;
        }
      }
      fprintf(fp2,"%d ",count);
      count=0;
      key=5;
      for(int i=0;i<iter;i++)
      {
        count++;
        if(*(a+i)==key)
        {
          break;
        }
      }
      fprintf(fp2,"%d\n ",count);
    }
}