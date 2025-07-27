#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int adj[MAX][MAX];  // Adjacency matrix
int indegree[MAX];  // In-degree array

void topologicalSort(int vertices) {
    // Calculate in-degree for each vertex
    for (int i = 0; i < vertices; i++)
        indegree[i] = 0;

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (adj[i][j])
                indegree[j]++;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < vertices; i++)
        if (indegree[i] == 0)
            enqueue(i);

    int count = 0;
    printf("Topological Order: ");

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        count++;

        // Remove v from graph and update in-degree of its neighbors
        for (int i = 0; i < vertices; i++) {
            if (adj[v][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if (count != vertices)
        printf("\nCycle detected! Topological sort not possible.\n");
    else
        printf("\n");
}

// Example usage
int main() {
    int vertices = 6;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adj[i][j] = 0;

    // Example DAG
    // 5 → 2, 5 → 0
    // 4 → 0, 4 → 1
    // 2 → 3
    // 3 → 1
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(vertices);

    return 0;
}
