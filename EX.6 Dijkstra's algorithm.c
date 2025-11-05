#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], visited[MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];

    for (int i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;

    for (int count = 1; count < n - 1; count++) {
        int min = INF, next = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                next = i;
            }

        visited[next] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                if (min + cost[next][i] < distance[i])
                    distance[i] = min + cost[next][i];
    }

    printf("\nShortest distances from city %d:\n", start + 1);
    for (int i = 0; i < n; i++)
        printf("To city %d = %d\n", i + 1, distance[i]);
}

int main() {
    int n, start;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter distance matrix (0 for no direct road):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting city number: ");
    scanf("%d", &start);

    dijkstra(graph, n, start - 1);
    return 0;
}
