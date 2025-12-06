//#pragma warning(disable:4996)
//#include <stdio.h>
//
//#define INF 30000 //초기값
//#define MAX 101
//
//void dijkstra(int n, int s, int adj[MAX][MAX]);
//
//int main(void) {
//    int n, m, s;
//    int adj[MAX][MAX];
//
//    scanf("%d %d %d", &n, &m, &s);
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            adj[i][j] = INF;
//
//    for (int i = 1; i <= n; i++)
//        adj[i][i] = 0;
//
//    for (int i = 0; i < m; i++) {
//        int u, v, w;
//        scanf("%d %d %d", &u, &v, &w);
//        adj[u][v] = w;
//        adj[v][u] = w;
//    }
//
//    dijkstra(n, s, adj);
//    return 0;
//}
//
//void dijkstra(int n, int s, int adj[MAX][MAX]) {
//    int dist[MAX];
//    int visited[MAX] = { 0 };
//
//    for (int i = 1; i <= n; i++)
//        dist[i] = INF;
//
//    dist[s] = 0;
//
//    for (int i = 1; i <= n; i++) {
//        int u = -1, min = INF;
//
//        // 방문하지 않은 정점 중 최단거리 정점 선택
//        for (int j = 1; j <= n; j++) {
//            if (!visited[j] && dist[j] < min) {
//                min = dist[j];
//                u = j;
//            }
//        }
//
//        if (u == -1) break;
//        visited[u] = 1;
//
//        // 인접 정점 거리 갱신
//        for (int v = 1; v <= n; v++) {
//            if (!visited[v] && adj[u][v] != INF) {
//                if (dist[u] + adj[u][v] < dist[v]) {
//                    dist[v] = dist[u] + adj[u][v];
//                }
//            }
//        }
//    }
//
//    for (int i = 1; i <= n; i++) {
//        if (i != s && dist[i] != INF) {
//            printf("%d %d\n", i, dist[i]);
//        }
//    }
//}
