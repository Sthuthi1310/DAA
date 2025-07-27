#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 10
#define y 100
#define z 10

int binarysearch(int *a, int low, int high, int key, int count) {
    int mid;
    count++;
    if (low > high) {
        return count - 1;
    }
    mid = (low + high) / 2;
    if (*(a + mid) == key) {
        return count;
    } else if (key < *(a + mid)) {
        return binarysearch(a, low, mid - 1, key, count);
    } else {
        return binarysearch(a, mid + 1, high, key, count);
    }
}

int main() {
    int *a, key, low, high;
    int count = 0;
    FILE *fp1, *fp2;
    srand(time(NULL));

    fp1 = fopen("numbersb.txt", "w");
    fp2 = fopen("Countss.txt", "w");

    fprintf(fp2, "Size BestCase AvgCase WorstCase\n");

    for (int iter = x; iter <= y; iter += z) {
        count = 0;
        low = 0;
        high = iter - 1;

        a = (int *)malloc(iter * sizeof(int));
        if (!a) {
            printf("Memory allocation failed.\n");
            exit(0);
        }

        *(a + 0) = rand()%10; 
        fprintf(fp1, "%d\n", *(a + 0));
        for (int i = 1; i < iter; i++) {
            *(a + i) = *(a + i - 1) + 2;
            fprintf(fp1, "%d\n", *(a + i));
        }

        // Best case: Middle element
        key = *(a + (low + high) / 2);
        count = binarysearch(a, low, high, key, 0);
        fprintf(fp2, "%d %d ", iter, count);

        // Average case: First quarter
        key = *(a + (iter / 4));
        count = binarysearch(a, low, high, key, 0);
        fprintf(fp2, "%d ", count);

        // Worst case: Not in array
        key = 60000;
        count = binarysearch(a, low, high, key, 0);
        fprintf(fp2, "%d\n", count);

        free(a);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
