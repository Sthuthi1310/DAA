#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stringmatch(char T[],char P[])
{
    int n=strlen(T);
    int m=strlen(P);
    int count=0;
    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        while(j<m&&P[j]==T[i+j])
        {
            count++;
            j=j+1;
        }
        if(j==m)
        break;
    }
    return count;
}
int main()
{
    char T[100],P[100];
    int index;
    FILE *fp1,*fp2;
    fp1=fopen("String.txt","w");
    fp2=fopen("CountStr.txt","w");
    for(int iter=1;iter<=10;iter++)
    {
        printf("Enter the string: ");
        scanf("%s",T);
        fprintf(fp1,"%s  ",T);
        //Best case
        printf("Enter the pattern: ");
        scanf("%s",P);
        fprintf(fp1,"%s\n",P);
        index=stringmatch(T,P);
        fprintf(fp2,"%d %d ",iter,index);
        //Average case
        printf("Enter the pattern: ");
        scanf("%s",P);
        fprintf(fp1,"%s\n",P);
        index=stringmatch(T,P);
        fprintf(fp2,"%d ",index);
        //Worst case
        printf("Enter the pattern: ");
        scanf("%s",P);
        fprintf(fp1,"%s\n",P);
        index=stringmatch(T,P);
        fprintf(fp2,"%d\n",index);
    }
}