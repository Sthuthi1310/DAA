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
    for(int iter=x;iter<=y;iter+=z)
    {
      count=0;
      fp1=fopen("number.txt","a");
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
      fp2=fopen("Counts.txt","a");
      key=5;
      for(int i=0;i<iter;i++)
      {
        count++;
        if(*(a+i)==key)
        {
          break;
        }
      }
      fprintf(fp2,"%d %d\n",iter,count);
    }
}