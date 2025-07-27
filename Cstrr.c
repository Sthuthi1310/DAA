#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
int stringmatch(char T[], char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            count++;
            if (P[j] != T[i + j])
                break;
            j++;
        }
        if (j == m)
            break;
    }
    return count;
}

int main() {
    char *T, *P;
    int count=0;
    FILE *fp1, *fp2;

    fp1 = fopen("cstring.txt", "w");   
    fp2 = fopen("CountStr.txt", "w");
    for(int iter=10;iter<=100;iter+=10)
    {
        T = (char*)malloc((iter + 1) * sizeof(char));
        P = (char*)malloc((iter-1 + 1) * sizeof(char));
        T[iter] = '\0';
        P[iter-1] = '\0';

        fprintf(fp1,"Iteration-%d\n",iter/10);
        for(int i=0;i<iter;i++)
        {
            T[i]='a';
            fprintf(fp1,"%c",T[i]);
        }
        fprintf(fp1,"\n");
        //Best case
        for(int i=0;i<(iter-1);i++)
        {
            P[i]='a';
            fprintf(fp1,"%c",P[i]);
        }
        fprintf(fp1,"\n");
        count=stringmatch(T,P);
        fprintf(fp2,"%d %d ",iter,count);

        //Average case
        count=0;
        P[iter-3]='b';
        for(int i=0;i<(iter/2);i++)
        {
            fprintf(fp1,"%c",P[i]);
        }
        fprintf(fp1,"\n");
        count=stringmatch(T,P);
        fprintf(fp2,"%d ",count);
        //Worst case
        count=0;
        P[iter-3]='a';
        P[iter-2]='b';
        for(int i=0;i<(iter-1);i++)
        {
            fprintf(fp1,"%c",P[i]);
        }
        fprintf(fp1,"\n");
        count=stringmatch(T,P);
        fprintf(fp2,"%d\n",count);
    }
    fclose(fp1);
    fclose(fp2);
    free(T);
    free(P);

    return 0;
}
