#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int parent[MAX];
int n;

void DFS(int v, int comp[], int *size, bool *hasCycle) {
    visited[v] = true;
    comp[(*size)++] = v;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                parent[i] = v;
                DFS(i, comp, size, hasCycle);
            } else if (i != parent[v]) {
                // Back edge found
                *hasCycle = true;
            }
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v format, 0-based indexing):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }

    int componentCount = 0;
    bool isCyclic = false;

    printf("\nConnected Components:\n");

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int comp[MAX];
            int size = 0;
            DFS(i, comp, &size, &isCyclic);

            printf("Component %d: ", ++componentCount);
            for (int j = 0; j < size; j++)
                printf("%d ", comp[j]);
            printf("\n");
        }
    }

    if (componentCount == 1)
        printf("\nGraph is CONNECTED\n");
    else
        printf("\nGraph is NOT CONNECTED\n");

    if (isCyclic)
        printf("Graph is CYCLIC\n");
    else
        printf("Graph is ACYCLIC\n");

    return 0;
}
