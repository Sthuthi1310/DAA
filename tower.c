#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void toh(int n, char A, char B, char C) {
    if (n == 1) {
        count++;
        return;
    }
    toh(n - 1, A, C, B);
    count++;
    toh(n - 1, B, A, C);
}

int main() {
    int n;
    FILE *fp;
    srand(time(0));

    fp = fopen("CountTOH.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 1; i <= 10; i++) {
        n = (rand() % 9) + 1;  // ensures n is between 1 and 9
        count = 0;
        toh(n, 'A', 'B', 'C');
        fprintf(fp, "Disks: %d, Moves: %d\n", n, count);
    }

    fclose(fp);
    printf("Move counts written to CountTOH.txt\n");

    return 0;
}
