#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

// Returns index of the largest element between indices l and r
int largest(int a[], int l, int r) {
    if (l == r)
        return l;  // Return index, not count

    count++;  // One comparison will be made later
    int mid = (l + r) / 2;
    int maxl = largest(a, l, mid);
    int maxr = largest(a, mid + 1, r);

    if (a[maxl] >= a[maxr])
        return maxl;
    else
        return maxr;
}

int main() {
    int *a;
    FILE *fp1, *fp2;
    fp1 = fopen("lnum.txt", "w");
    fp2 = fopen("lcount.txt", "w");

    if (!fp1 || !fp2) {
        printf("File error\n");
        return 1;
    }

    srand(time(NULL));

    for (int iter = 10; iter <= 100; iter += 10) {
        a = (int *)malloc(iter * sizeof(int));
        if (!a) {
            printf("No memory\n");
            return 1;
        }

        // Best case: max at beginning
        a[0] = rand() % 1000 + 100;
        fprintf(fp1, "Best: ");
        for (int i = 1; i < iter; i++) {
            a[i] = a[i - 1] - 25;
        }
        for (int i = 0; i < iter; i++)
            fprintf(fp1, "%d ", a[i]);
        fprintf(fp1, "\n");

        count = 0;
        largest(a, 0, iter - 1);
        fprintf(fp2, "%d %d ", iter, count);

        // Average case: random
        fprintf(fp1, "Avg:  ");
        for (int i = 0; i < iter; i++) {
            a[i] = rand() % 1000;
            fprintf(fp1, "%d ", a[i]);
        }
        fprintf(fp1, "\n");

        count = 0;
        largest(a, 0, iter - 1);
        fprintf(fp2, "%d ", count);

        // Worst case: max at end
        fprintf(fp1, "Worst:");
        a[0] = rand() % 100;
        for (int i = 1; i < iter; i++) {
            a[i] = a[i - 1] + 25;
        }
        for (int i = 0; i < iter; i++)
            fprintf(fp1, "%d ", a[i]);
        fprintf(fp1, "\n");

        count = 0;
        largest(a, 0, iter - 1);
        fprintf(fp2, "%d\n", count);

        free(a);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
