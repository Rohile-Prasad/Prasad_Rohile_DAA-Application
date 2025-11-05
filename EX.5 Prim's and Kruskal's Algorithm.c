#include <stdio.h>

#define INF 9999
#define MAX 10

void prims(int cost[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int edges = 0, total = 0;
    visited[0] = 1;
    printf("\nPrim's MST:\n");
    while (edges < n - 1) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("Edge: %d - %d  Cost: %d\n", a + 1, b + 1, min);
        total += min;
        visited[b] = 1;
        edges++;
    }
    printf("Total cost using Prim's: %d\n", total);
}

void kruskal(int cost[MAX][MAX], int n) {
    int parent[MAX];
    for (int i = 0; i < n; i++) parent[i] = i;

    int total = 0, edges = 0;
    printf("\nKruskal's MST:\n");

    while (edges < n - 1) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][j] && cost[i][j] < min && parent[i] != parent[j]) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        int old = parent[a], new = parent[b];
        for (int k = 0; k < n; k++)
            if (parent[k] == old) parent[k] = new;

        printf("Edge: %d - %d  Cost: %d\n", a + 1, b + 1, min);
        total += min;
        cost[a][b] = cost[b][a] = INF;
        edges++;
    }
    printf("Total cost using Kruskal's: %d\n", total);
}

int main() {
    int n;
    printf("Enter number of offices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];
    printf("Enter cost adjacency matrix (0 for no connection):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF;
        }

    prims(cost, n);
    kruskal(cost, n);
    return 0;
}
