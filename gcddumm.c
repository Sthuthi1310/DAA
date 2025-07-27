#include<stdio.h>
#include<stdlib.h>

int count=0;
int Euclid_gcd(int a,int b){
    count=0;
    while(b!=0){
        count++;
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}

int consecutive_integer(int a,int b){
    count=0;
    int gcd=1;
    int min=(a<b)?a:b;
    while(min!=0){
        count++;
        if(a%min==0 && b%min==0){
           gcd=min;
           break;
        }
        min--;
    }
    return gcd;
}

int modified_euclids(int a,int b){
    count=0;
    while(a!=b){
        count++;
        if(a>b){
            a=a-b;
        }else{
            b=b-a;
        }
    }
    return a;
}

void tester(){
    int a,b;
    printf("Enter the value of a\n");
    scanf("%d",&a);
    printf("Enter the value b\n");
    scanf("%d",&b);
    printf("The GCD using the Euclid's method is %d\n",Euclid_gcd(a,b));
    printf("The GCD using the consecutive Integer method is %d\n",consecutive_integer(a,b));
    printf("The GCD using the Modified Euclid's method is %d\n",modified_euclids(a,b));

}

void plotter() {
    int a, b;
    int count1, count2, count3;

    FILE *fp1 = fopen("BestCase.txt", "w");
    FILE *fp2 = fopen("AverageCase.txt", "w");
    FILE *fp3 = fopen("WorstCase.txt", "w");

    // Best case inputs
    printf("Enter the inputs for the best case:\n");
    for (int k = 1; k < 10; k++) {
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);

        Euclid_gcd(a, b);
        count1 = count;

        modified_euclids(a, b);
        count2 = count;

        consecutive_integer(a, b);
        count3 = count;

        fprintf(fp1, "%d %d %d %d\n", k, count1, count2, count3);
    }

    // Average case inputs
    printf("Enter the inputs for the average case:\n");
    for (int k = 1; k < 10; k++) {
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);

        Euclid_gcd(a, b);
        count1 = count;

        modified_euclids(a, b);
        count2 = count;

        consecutive_integer(a, b);
        count3 = count;

        fprintf(fp2, "%d %d %d %d\n", k, count1, count2, count3);
    }

    // Worst case inputs
    printf("Enter the inputs for the worst case:\n");
    for (int k = 1; k < 10; k++) {
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);

        Euclid_gcd(a, b);
        count1 = count;

        modified_euclids(a, b);
        count2 = count;

        consecutive_integer(a, b);
        count3 = count;

        fprintf(fp3, "%d %d %d %d\n", k, count1, count2, count3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

void main(){
    int ch;
    
    printf("\n1. tester\n2. plotter\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        tester();
        break;\

        case 2:
        plotter();
        break;

        default:
        printf("Invalid choice!!");
    }
}