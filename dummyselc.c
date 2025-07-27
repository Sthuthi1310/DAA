#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
#define z 10


int selectionsort(int *a,int n){
    int min,count=0;
    for (int i=0;i<=n-2;i++){
        min=i;
        for(int j=i+1;j<=n-1;j++){
            count++;
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    return count;
}
void tester(){
    int *a,n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    printf("Elements before sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    selectionsort(a,n);
    printf("\nElements after sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}
void plotter(){
    int *a,n,count1=0,count2=0,count3=0;
    srand(time(NULL));
    FILE *fp1,*fp2;
    fp1=fopen("selection_number.txt","w");
    fp2=fopen("selection_count.txt","w");
    printf("plotting graph\n");
    for(n=10;n<=100;n+=10){
        a=(int*)malloc(n*sizeof(int));
        if(a==NULL){
            printf("no memory\n");
            exit(1);
        }
        //best case
        a[0]=rand()%100;
        fprintf(fp1,"%d\t",a[0]);
        for(int i=1;i<n;i++){
            a[i]=a[i-1]+2;
            fprintf(fp1,"best case:%d\t",a[i]);
        }
        fprintf(fp1,"\n");
        count1=selectionsort(a,n);
        fprintf(fp2,"%d\t%d\t",n,count1);

        //average case
        for(int i=0;i<n;i++){
            a[i]=rand()%100;
            fprintf(fp1,"avg case:%d\t",a[i]);
        }
        fprintf(fp1,"\n");
        count2=selectionsort(a,n);
        fprintf(fp2,"%d\t",count2);

        //worst case
        a[0]=rand()%1000;
        fprintf(fp1,"worst case:%d\t",a[0]);
        for(int i=1;i<n;i++){
            a[i]=a[i-1]-2;
            fprintf(fp1,"%d\t",a[i]);
        }
        fprintf(fp1,"\n");
        count3=selectionsort(a,n);
        fprintf(fp2,"%d\n",count3);
        free(a);
    }
    fclose(fp1);
    fclose(fp2);

}
int main(){
    int choice;
    printf("\nEnter your choice:\n1.Tester\n2.Plotter\n3.exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:tester();
        break;
        case 2:plotter();
        break;
        case 3:
        printf("Exiting program\n");
        exit(0);
        default:
        printf("invalid choice\n");
    }
    return 0;
}