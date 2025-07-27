#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a, *b, *c, m, n, p = 0;

    printf("Enter the size of the arrays: ");
    scanf("%d%d", &m, &n);

    a = (int*)malloc(m * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    c = (int*)malloc((m < n ? m : n) * sizeof(int)); // max possible intersection

    if (a == NULL || b == NULL || c == NULL) {
        printf("No memory\n");
        exit(0);
    }

    printf("Enter the elements of array a: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);

    printf("Enter the elements of array b: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                c[k++] = a[i];
                p++;
                break; // to avoid multiple matches of same a[i]
            }
        }
    }

    printf("Common elements are: ");
    for (int j = 0; j < p; j++) {
        printf("%d ", c[j]);
    }

    // Optional: Free allocated memory
    free(a);
    free(b);
    free(c);

    return 0;
}
