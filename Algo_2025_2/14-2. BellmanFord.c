#pragma warning(disable:4996)
#include <stdio.h>

#define INF 30000
#define MAX 1001

typedef struct {
    int u, v, w;
} Edge;

void bellman_ford(int n, int m, int s, Edge edges[MAX]);

int main(void) {
    int n, m, s;
    Edge edges[MAX];

    scanf("%d %d %d", &n, &m, &s);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    bellman_ford(n, m, s, edges);
    return 0;
}

void bellman_ford(int n, int m, int s, Edge edges[MAX]) {
    int dist[101];

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[s] = 0;

    // 모든 간선을 n-1번 반복
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i != s && dist[i] != INF) {
            printf("%d %d\n", i, dist[i]);
        }
    }
}
