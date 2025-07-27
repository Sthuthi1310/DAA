#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int *Table,count=0;
void shifttable(char P[],int m)
{
    Table = (int*)malloc(256 * sizeof(int));
    if(Table==NULL)
    {
        printf("No memory\n");
        exit(0);
    }
    for (int i = 0; i < 256; i++) {
    Table[i] = m;
}

    for(int i=0;i<m-1;i++)
    {
        Table[P[i]]=m-1-i;
    }
}
int stringmatch(char P[],char T[],int m,int n)
{
    shifttable(P,m);
    int i=m-1;
    while(i<=n-1)
    {
        int k=0;
        count++;
        while(k<=m-1&&P[m-1-k]==T[i-k])
        {
            k=k+1;
        }
        if(k==m)
        return count;
        else
        i=i+Table[T[i]];
    }
    return count;
}
int main()
{
    char T[100],P[100];
    int index,m,n;
    FILE *fp1,*fp2;
    fp1=fopen("HString.txt","w");
    fp2=fopen("HCountStr.txt","w");
    for(int iter=1;iter<=3;iter++)
    {
        printf("Enter the string: ");
        scanf("%s",T);
        fprintf(fp1,"%s  ",T);
        n=strlen(T);
        //Best case
        printf("Enter the pattern: ");
        scanf("%s",P);
        m=strlen(P);
        fprintf(fp1,"%s\n",P);
        count=stringmatch(T,P,m,n);
        fprintf(fp2,"%d %d ",iter,count);
        //Average case
        printf("Enter the pattern: ");
        scanf("%s",P);
        m=strlen(P);
        fprintf(fp1,"%s\n",P);
        count=stringmatch(T,P,m,n);
        fprintf(fp2,"%d ",count);
        //Worst case
        printf("Enter the pattern: ");
        scanf("%s",P);
        m=strlen(P);
        fprintf(fp1,"%s\n",P);
        count=stringmatch(T,P,m,n);
        fprintf(fp2,"%d\n",count);
    }
}