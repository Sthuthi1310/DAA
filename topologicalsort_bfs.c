#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int graph[MAX][MAX], inDegree[MAX];
int count = 0;

void reset(int n) {
    for (int i = 0; i < n; i++)
        inDegree[i] = 0;
    count = 0;
}

// Generate random DAG
void generateRandomDAG(int n, int edgeCount) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int added = 0;
    while (added < edgeCount) {
        int u = rand() % n;
        int v = rand() % n;
        if (u < v && graph[u][v] == 0) {
            graph[u][v] = 1;
            added++;
        }
    }
}

// Compute in-degrees
void computeInDegree(int n) {
    for (int i = 0; i < n; i++)
        inDegree[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            count++;
            if (graph[i][j])
                inDegree[j]++;
        }
}

// Topological sort by source removal
void topologicalSortSourceRemoval(int n) {
    computeInDegree(n);
    int processed = 0;
    int removed[MAX] = {0};

    printf("Topological Order (%d nodes): ", n);
    for (int step = 0; step < n; step++) {
        int foundSource = 0;

        for (int i = 0; i < n; i++) {
            if (!removed[i] && inDegree[i] == 0) {
                printf("%c ", i + 'A');
                removed[i] = 1;
                processed++;
                foundSource = 1;

                for (int j = 0; j < n; j++) {
                    count++;
                    if (graph[i][j])
                        inDegree[j]--;
                }

                break;
            }
        }

        if (!foundSource) break; // Cycle found
    }

    printf("\n");

    if (processed != n) {
        printf("Graph has a CYCLE. Topological sort not possible.\n");
    }
}

// Write operation count to file
void writeData(const char *filename, int n, int value) {
    FILE *f = fopen(filename, "a");
    fprintf(f, "%d\t%d\n", n, value);
    fclose(f);
}

// Plot using gnuplot
void plotWithGnuplot() {
    FILE *gp = popen("gnuplot -persistent", "w");
    fprintf(gp,
        "set title 'Topological Sort via Source Removal (Random DAGs)'\n"
        "set xlabel 'Number of Nodes'\n"
        "set ylabel 'Edge Checks'\n"
        "plot 'file.txt' with linespoints title 'Random DAG'\n"
    );
    pclose(gp);
}

int main() {
    srand(time(NULL));
    FILE *f = fopen("file.txt", "w");  // clear old
    fclose(f);

    for (int n = 2; n <= 20; n++) {
        int maxEdges = n * (n - 1) / 2;
        int edgeCount = rand() % (maxEdges + 1); // random number of edges

        generateRandomDAG(n, edgeCount);
        reset(n);
        topologicalSortSourceRemoval(n);
        writeData("file.txt", n, count);
    }

    plotWithGnuplot();
    return 0;
}