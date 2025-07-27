#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int  Factorial(int n){
    count++;
    if(n==0){
        return 1;
    }
    else{
        return n*Factorial(n-1);
    }
}
void tester(){
    int n,ans;
    printf("Enter a number to find it's Factorial\n");
    scanf("%d",&n);
    ans=Factorial(n);
    printf("Factorial of %d is %d\n",n,ans);
}
void plotter(){
    srand(time(NULL));
    int n,ip_size,r;  
    FILE *f1;
    f1=fopen("factorial.txt","w");
    ip_size=2;
    while(ip_size<=1500){
        n=rand()%ip_size+1;
        count=0;
        r=Factorial(n);
        fprintf(f1,"%d\t%d\n",n,count);
        ip_size=ip_size*2;
    }
    fclose(f1);
}
void main(){
    int ch;
    printf("Enter your choice:\n1.Tester\n2.Plotter\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            tester();
            break;
        case 2:
             plotter();
             break;
        default:
        printf("Invalid choice!!\n");
    }
}