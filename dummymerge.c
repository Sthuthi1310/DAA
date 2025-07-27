#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 10
#define Y 100
#define Z 10

int count = 0;

void merge(int *B, int s1, int *C, int s2, int *a)
{
    int i = 0, j = 0, k = 0;
    while (i < s1 && j < s2)
    {
    	count++;
        if (B[i] <= C[j])
            a[k++] = B[i++];
        else
            a[k++] = C[j++];
    }
    while (i < s1)
        a[k++] = B[i++];
    while (j < s2)
        a[k++] = C[j++];
}

void mergeSort(int *a, int n)
{
    if (n <= 1)
        return;

    int s1 = n / 2;
    int s2 = n - s1;

    int *B = (int *)malloc(s1 * sizeof(int));
    int *C = (int *)malloc(s2 * sizeof(int));

    for (int i = 0; i < s1; i++)
        B[i] = a[i];
    for (int i = 0; i < s2; i++)
        C[i] = a[s1 + i];

    mergeSort(B, s1);
    mergeSort(C, s2);
    merge(B, s1, C, s2, a);

    free(B);
    free(C);
}

void worstCase(int *a, int beg, int end)
{
    int i, j;
    if (beg == end)
        return;
    else
    {
        int mid = (beg + end) / 2;
        int n1 = (mid - beg) + 1;
        int n2 = end - mid;
        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
        {
            L[i] = a[2 * i];
        }

        for (j = 0; j < n2; j++)
        {
            R[j] = a[(2 * j) + 1];
        }

        worstCase(L, beg, mid);
        worstCase(R, mid + 1, end);

        for (i = 0; i < n1; i++)
        {
            a[i] = L[i];
        }

        for (j = 0; j < n2; j++)
        {
            a[i + j] = R[j];
        }
    }
}

int main()
{
    int *a, n, iter = 0;
    FILE *fp1, *fp2;
    srand(time(0));
    fp1 = fopen("file1.txt", "w");
    fp2 = fopen("file2.txt", "w");

    for (n = X; n <= Y; n += Z)
    {
        a = (int *)malloc(n * sizeof(int));
        fprintf(fp1, "Iteration=%d\n", iter);
        iter++;

        // Best Case
        fprintf(fp1, "Best Input: ");
        a[0] = rand() % 100;
        fprintf(fp1, "%d ", a[0]);
        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1] + rand() % 100;
            fprintf(fp1, "%d ", a[i]);
        }
        fprintf(fp1, "\n");

        count = 0;
        mergeSort(a, n);

        fprintf(fp1, "Best Output: ");
        for (int i = 0; i < n; i++)
        {
            fprintf(fp1, "%d ", a[i]);
            }
        fprintf(fp1, "\n");
        fprintf(fp1, "Best Count=%d\n\n\n", count);
        fprintf(fp2, "%d %d ", n, count);
       
       
       
       
       
       
       
       
       
       
        // worst Case
        fprintf(fp1, "worst Input: ");
        worstCase(a,0,n-1);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp1, "%d ", a[i]);
        }
        fprintf(fp1, "\n");

        count = 0;
        mergeSort(a, n);

        fprintf(fp1, "worst Output: ");
        for (int i = 0; i < n; i++)
        {
            fprintf(fp1, "%d ", a[i]);
            }
        fprintf(fp1, "\n");

        fprintf(fp1, "worst Count=%d\n\n\n", count);
        fprintf(fp2, "%d ",count);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
         //average Case
        fprintf(fp1, "average Input: ");
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100;
            fprintf(fp1, "%d ", a[i]);
        }
        fprintf(fp1, "\n");

        count = 0;
        mergeSort(a, n);

        fprintf(fp1, "average Output: ");
        for (int i = 0; i < n; i++)
        {
            fprintf(fp1, "%d ", a[i]);
            }
        fprintf(fp1, "\n");

        fprintf(fp1, "avearaget Count=%d\n\n\n\n\n\n", count);
        fprintf(fp2, "%d\n",count);
        
        }
        }