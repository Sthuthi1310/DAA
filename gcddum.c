#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gcd(int m, int n, int i)
{
    int count1 = 0, count2 = 0, count3 = 0;
    FILE *fp1 = fopen("gcdnumm.txt", "a");
    FILE *fp2 = fopen("gcdcountt.txt", "a");
    int min;
    int a = m, b = n, x = m, y = n;

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Euclid's method
    while (n != 0) {
        count1++;
        int temp = n;
        n = m % n;
        m = temp;
    }

    // Modified Euclid's method
    while (a != b) {
        count2++;
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    // Consecutive Integer Checking method
    min = (x < y) ? x : y;
    while (min > 0) {
        count3++;
        if (x % min == 0 && y % min == 0)
            break;
        min--;
    }

    // Write results
    fprintf(fp1, "Run %d:\n", i);
    fprintf(fp1, "GCD(EUCLID) is %d\n", m);
    fprintf(fp1, "GCD(MODIFIED EUCLID) is %d\n", a);
    fprintf(fp1, "GCD(CONSECUTIVE INTEGER) is %d\n\n", min);
    fprintf(fp2, "%d %d %d %d\n", i, count1, count2, count3);

    fclose(fp1);
    fclose(fp2);
}

int main()
{
    int m, n;
    for (int i = 1; i <= 5; i++) {
        printf("Enter the value of m and n: ");
        scanf("%d%d", &m, &n);
        gcd(m, n, i);
    }
    return 0;
}
