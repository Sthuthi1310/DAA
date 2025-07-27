#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int opcount;

void merge(int b[],int c[],int a[],int p,int q){
    int i=0,j=0,k=0;
    while(i<p && j<q){
        opcount++;
        if(b[i]<c[j]){
            a[k++]=b[i++];
           
        }else{
            a[k++]=c[j++];
           
        }
     
    }
    if(i==p){
        while(j<q && k<(p+q)){
            a[k++]=c[j++];
        }
    }else{
        while(i<p && k<(p+q)){
            a[k++]=b[i++];
        }
    }

}
void merge_sort(int a[],int n){
     int *b;
     int *c;
     int p=n/2;
     int q=n-p;
     b=(int *)malloc(p*sizeof(int));
     c=(int *)malloc(q*sizeof(int));
     if(n<=1){
        return;
     }
     for(int i=0;i<p;i++){
        b[i]=a[i];
     }

      for(int i=0;i<q;i++){
        c[i]=a[p+i];
     }
     merge_sort(b,p);
     merge_sort(c,q);
     merge(b,c,a,p,q);
}
void worst_case(int arr[],int s,int e){
    int i,j;
    if(s==e){
        return;
    }
    int mid=(s+e)/2;
    int n1=mid-s+1;
    int n2=e-mid;
    int l[n1],r[n2];
    for( i=0;i<n1;i++){
        l[i]=arr[2*i];
    }

    for( j=0;j<n2;j++){
        r[j]=arr[s+2*j+1];
    }
worst_case(l,s,mid);
worst_case(r,mid+1,e);

for( i=0;i<n1;i++){
    arr[i]=l[i];
}
for( j=0;j<n2;j++){
   arr[i+j]=r[j];
}
}


void tester(){
    int n;
    printf("Enter the size of an array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,n);
    printf("The sorted order is\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void plotter(){
    srand(time(NULL));
    FILE *fp1;
    FILE *fp2;
    int *arr;  
    int count1=0,count2=0,count3=0;
    fp1=fopen("M1.txt","w");
    fp2=fopen("M2.txt","w");
    for(int k=10;k<=100;k+=10){
        opcount=0;
   
      
        arr=(int *)malloc(k*sizeof(int));
        //Best case 
        opcount=0;
       arr[0]=rand()%100;
       fprintf(fp1,"%d ",arr[0]);
       for(int i=1;i<k;i++){
        arr[i]=arr[i-1]+2;
        fprintf(fp1,"%d ",arr[i]);
       }
       fprintf(fp1,"\n");
       merge_sort(arr,k);
       count1=opcount;
       

       //Avearge case 
       opcount=0;
       for(int i=0;i<k;i++){
        arr[i]=rand()%100;
        fprintf(fp1,"%d ",arr[i]);
       }
       fprintf(fp1,"\n");
       merge_sort(arr,k);
       count2=opcount;

       //worst case
       opcount=0;
       arr[0]=rand()%100;
       fprintf(fp1,"%d ",arr[0]);
       for(int i=1;i<k;i++){
        arr[i]=arr[i-1]+2;
        fprintf(fp1,"%d ",arr[i]);
       }
       worst_case(arr,0,k);
       for(int i=0;i<k;i++){
        fprintf(fp1,"%d ",arr[i]);
       }
       fprintf(fp1,"\n");
       merge_sort(arr,k);
       count3=opcount;
       fprintf(fp2,"%d %d %d %d\n",k,count1,count2,count3);
    }

}

int main()
{
    int ch;
        printf("\nEnter your choice:\n1. Tester\n2. Plotter\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            tester();
            break;
        case 2:
            plotter();
            break;
        default:
            printf("Invalid choice!\n");
        }
    return 0;
}