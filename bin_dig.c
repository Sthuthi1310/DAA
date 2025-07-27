#include <stdio.h>
#include <stdlib.h>
int Count=0;
// Proper recursive function to count steps dividing by 2 until 1
int count(int n) {
    Count++;
    if (n == 1)
        return 1;
    else
     count(n / 2) + 1;
     return Count;
}

int main() {
    int n, num = 0;
    FILE *fp1, *fp2;

    fp1 = fopen("numbin.txt", "w");
    fp2 = fopen("countbin.txt", "w");

    // Check if files opened successfully
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("Enter the number: ");
        scanf("%d", &n);
        fprintf(fp1, "%d\n", n);

        num = count(n);
        fprintf(fp2, "%d %d\n", n, num);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
