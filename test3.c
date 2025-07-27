#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int  BinDigit(int n){
    count++;
    if(n==1){
        return 1;
    }
    else{
        return (BinDigit(n/2)+1);
    }
}
void main(){
    srand(time(NULL));
    int n, r;  
    FILE *f1;
    f1=fopen("BinaryDigit.txt","w");
   n=2;
    while(n<=1500){
        count=0;
        r=BinDigit(n);
        fprintf(f1,"%d\t%d\n",n,count);
       n=n*2;
    }
    fclose(f1);
}
