#include<stdio.h>
#include<stdlib.h>

int count=0;

int binary_search(int arr[],int s,int e,int key){
    
    count++;
    if(s>e){
        count--;
        return -1 ;
    }
     
    int mid=(s+e)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]>key){
        return binary_search(arr,s,mid-1,key);
    }else{
          return binary_search(arr,mid+1,e,key);
    }
    
    
}

void tester(){
    int n;
    int key;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    int arr[n];
    int s=0;
    int e=n-1; 
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the  key element\n");
    scanf("%d",&key);
    int ans;
    ans=binary_search(arr,s,e,key);
    if(ans!=-1){
        printf("The key  %d   found\n",key);
    }else{
        printf("The key  %d  not found\n",key);
    }
}

void plotter(){
    int key;
    int *arr;
    FILE *fp1;
    FILE *fp2;
    fp1=fopen("Bin_Number.txt","w");
    fp2=fopen("Bin_Count.txt","w");
    int count1=0,count2=0,count3=0;
    for(int k=10;k<=100;k+=10){
        count=0;
        arr=(int *)malloc(k*sizeof(int));
        int s=0;
        int e=k-1;

        //Best Case 
        for(int i=0;i<k;i++){
            arr[i]=rand()%100;
            fprintf(fp1,"%d ",arr[i]);
        }
        fprintf(fp1,"\n");
        key=arr[(s+e)/2];
        binary_search(arr,s,e,key);
        count1=count;

        count=0;
        //Average case
        for(int i=0;i<k;i++){
            arr[i]=rand()%100;
            fprintf(fp1,"%d ",arr[i]);
        }
        fprintf(fp1,"\n");
        key=arr[(s+e)/4];
        binary_search(arr,s,e,key);
        count2=count;

        count=0;
        //Worst Case
        for(int i=0;i<k;i++){
            arr[i]=rand()%100;
            fprintf(fp1,"%d ",arr[i]);
        }
        fprintf(fp1,"\n");
        key=4444;
        binary_search(arr,s,e,key);
        count3=count;

        fprintf(fp2,"%d %d %d %d\n",k,count1,count2,count3);




    }

}

void main(){
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
    return ;
    
}



