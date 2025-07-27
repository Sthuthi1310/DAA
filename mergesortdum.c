#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
#define z 10

// Forward declarations
int merge(int b[], int c[], int a[], int p, int q);
int mergesort(int a[], int n);
void worstcase(int a[], int beg, int end);
void tester();
void plotter();

int merge(int b[], int c[], int a[], int p, int q) {
    int i = 0, j = 0, k = 0, count = 0;
    while (i < p && j < q) {
        count++;
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = c[j++];
        }
    }
    while (i < p) {
        a[k++] = b[i++];
    }
    while (j < q) {
        a[k++] = c[j++];
    }
    return count;
}

int mergesort(int a[], int n) {
    int *b, *c, p, q, count_merge = 0;
    if (n <= 1) {
        return 0;
    }
    p = n / 2;
    q = n - p;
    b = (int*)malloc(p * sizeof(int));
    c = (int*)malloc(q * sizeof(int));
    if (b == NULL || c == NULL) {
        printf("no memory\n");
        exit(0);
    }
    for (int i = 0; i < p; i++) {
        b[i] = a[i];
    }
    for (int i = 0; i < q; i++) {
        c[i] = a[p + i];
    }
    count_merge += mergesort(b, p);
    count_merge += mergesort(c, q);
    count_merge += merge(b, c, a, p, q);
    free(b);
    free(c);
    return count_merge;
}

void worstcase(int a[], int beg, int end) {
    if ((end - beg) <= 1) {
        return;
    }
    int mid = (beg + end) / 2;
    int size = end - beg;
    int t = (int)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        t[i] = a[beg + i];
    }
    worstcase(t, 0, (size / 2));
    worstcase(t + (size / 2), 0, (size - (size / 2)));
    for (int i = 0; i < (size / 2); i++) {
        a[beg + 2 * i] = t[i];
    }
    for (int i = 0; i < (size - (size / 2)); i++) {
        a[beg + (2 * i) + 1] = t[(size / 2) + i];
    }
    free(t);
}

void tester() {
    int *a, n;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Elements before sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    mergesort(a, n);
    printf("\nElements after sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
}

void plotter() {
    int *a, n, count1 = 0, count2 = 0, count3 = 0;
    srand(time(NULL));
    FILE *fp1 = fopen("merge_num.txt", "w");
    FILE *fp2 = fopen("merge_count.txt", "w");
    for (n = x; n <= y; n += z) {
        a = (int*)malloc(n * sizeof(int));
        // Best case (sorted)
        for (int i = 0; i < n; i++) {
            a[i] = i * 2;
            fprintf(fp1, "%d\t", a[i]);
        }
        fprintf(fp1, "\n");
        count1 = mergesort(a, n);
        fprintf(fp2, "%d\t%d\t", n, count1);
        // Average case (random)
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100;
            fprintf(fp1, "%d\t", a[i]);
        }
        fprintf(fp1, "\n");
        count2 = mergesort(a, n);
        fprintf(fp2, "%d\t", count2);
        // Worst case (reverse sorted + shuffled)
        for (int i = 0; i < n; i++) {
            a[i] = n - i;
        }
        worstcase(a, 0, n);
        for (int i = 0; i < n; i++) {
            fprintf(fp1, "%d\t", a[i]);
        }
        fprintf(fp1, "\n");
        count3 = mergesort(a, n);
        fprintf(fp2, "%d\n", count3);
        free(a);
    }
    fclose(fp1);
    fclose(fp2);
}

int main() {
      
    int choice;
    while(1) {
        printf("\nEnter your choice:\n1. Tester\n2. Plotter\n3. Exit\n ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: tester();
             break;
            case 2: plotter();
             break;
            case 3: printf("Exiting from program\n"); 
            return 0;
            default: 
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}