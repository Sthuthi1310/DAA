#include <stdio.h>
#include <string.h>

int stringmatch(char *a, char *p) {
    int count = 0, i, j;
    int n = strlen(a), m = strlen(p);

    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m) {
            count++;
            if (p[j] != a[i + j])
                break;
            j++;
        }
        if (j == m)
            return count;  // Pattern found
    }
    return -1;  // Pattern not found
}

int main() {
    char a[100], p[100];
    int count;
    FILE *fp1, *fp2;

    fp1 = fopen("string.txt", "w");
    fp2 = fopen("index.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int iter = 1; iter <= 3; iter++) {
        printf("Enter the input string: ");
        scanf("%s", a);

        fprintf(fp1, "%s\t", a);

        // Best case: pattern is first character
        p[0] = a[0];
        p[1] = '\0';

        count = stringmatch(a, p);
        fprintf(fp2, "%d %d\n", iter, count);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
