#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void heapify(int H[], int n, int i, int *count) {
    int k = i;
    int v = H[k];
    int heap = 0;

    while (!heap && 2 * k <= n) {
        int j = 2 * k;
        (*count)++;

        if (j < n && H[j] < H[j + 1]) {
            j = j + 1;
        }

        (*count)++;
        if (v >= H[j]) {
            heap = 1;
        } else {
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}


int heap_sort(int H[], int n) {
    int count = 0;

    for (int i = n / 2; i >= 1; i--) {
        heapify(H, n, i, &count);
    }

    for (int i = n; i > 1; i--) {
    
        int temp = H[1];
        H[1] = H[i];
        H[i] = temp;

      
        heapify(H, i - 1, 1, &count);
    }

    return count;
}

int main() {
    int *H;
    FILE *fp1, *fp2;
    srand(time(NULL));

    fp1 = fopen("H1.txt", "w");
    fp2 = fopen("H2.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("File error.\n");
        return 1;
    }

    for (int iter = 10; iter <= 100; iter += 10) {
        H = (int *)malloc((iter + 1) * sizeof(int)); // 1-based indexing

        if (H == NULL) {
            printf("No memory\n");
            exit(0);
        }

        // Best Case: sorted ascending
        H[1] = rand() % 100;
        fprintf(fp1, "Best (%d): %d ", iter, H[1]);
        for (int i = 2; i <= iter; i++) {
            H[i] = H[i - 1] - 5;
            fprintf(fp1, "%d ", H[i]);
        }
        fprintf(fp1, "\n");
        int count = heap_sort(H, iter);
        fprintf(fp2, "%d %d ", iter, count);

        // Average Case: random
        for (int i = 1; i <= iter; i++) {
            H[i] = rand() % 100;
            fprintf(fp1, "%d ", H[i]);
        }
        fprintf(fp1, "\n");
        count = heap_sort(H, iter);
        fprintf(fp2, "%d ", count);

        // Worst Case: sorted descending
        H[1] = rand() % 100;
        fprintf(fp1, "%d ", H[1]);
        for (int i = 2; i <= iter; i++) {
            H[i] = H[i - 1] + 5;
            fprintf(fp1, "%d ", H[i]);
        }
        fprintf(fp1, "\n");
        count = heap_sort(H, iter);
        fprintf(fp2, "%d\n", count);

        free(H);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
