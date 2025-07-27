#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
int string_match(char t[],char p[]){
    count=0;
    int n=strlen(t);
    int m=strlen(p);
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m){
            count++;
            if(p[j]!=t[i+j]){
                break;
               
            }
             j++;
        }
        if(j==m){
            return i;
        }
    }
    return -1;


}
void tester(){
    char t[100],p[50];
    printf("Enter the text\n");
    scanf("%s",t);
    printf("Enter the pattern\n");
    scanf("%s",p);
    int ans;
    ans=string_match(t,p);
   printf("%d",ans);

    
}
void plotter(){
    char t[100],p[100];
    FILE *fp1;
    FILE *fp2;
    int count1=0,count2=0,count3=0;
    fp1=fopen("Str_Number.txt","w");
    fp2=fopen("str_count.txt","w");
    for(int k=10;k<=100;k+=10){
        for(int i=0;i<k;i++){
            t[i]='a';
            fprintf(fp1,"%c ",t[i]);
        }
        fprintf(fp1,"\n");

        //Best case 
        string_match(t,"aaa");
        count1=count;

        //Avearge case
        string_match(t,"aba");
        count2=count;

        //Worst case
        string_match(t,"aab");
        count3=count;

        fprintf(fp2,"%d %d %d %d\n",k,count1,count2,count3);


      
    }
}

int main() {
    int ch;
    printf("Enter your choice:\n1. Tester\n 2. Plotter\n");
    scanf("%d", &ch);
    switch(ch) {
        case 1:
            tester();
            break;

            case 2:
            plotter();
            break;
        default:
            printf("Invalid choice!!\n");
    }
    return 0;
}