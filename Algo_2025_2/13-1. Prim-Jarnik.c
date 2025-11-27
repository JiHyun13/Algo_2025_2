//#pragma warning(disable:4996)
//#include <stdio.h>
//
//#define N 101
//
//int w[N][N], used[N], dist[N];
//int n, m;
//
//int main() {
//    scanf("%d %d", &n, &m);
//
//    // 간선 없음 = 0으로 두되 자기자신 제외
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            w[i][j] = 0;
//
//    // 무방향 입력
//    for (int i = 0; i < m; i++) {
//        int a, b, c;
//        scanf("%d %d %d", &a, &b, &c);
//        w[a][b] = w[b][a] = c;
//    }
//
//    // 거리 -1이면 아직 값 없다는 뜻
//    for (int i = 1; i <= n; i++) dist[i] = -1;
//    dist[1] = 0; // 시작정점
//
//    int sum = 0;
//
//    for (int k = 1; k <= n; k++) {
//        int v = -1;
//
//        // 선택되지 않은 정점 중 dist가 가장 작은 것
//        for (int i = 1; i <= n; i++) {
//            if (!used[i] && dist[i] != -1) {
//                if (v == -1 || dist[i] < dist[v])
//                    v = i;
//            }
//        }
//
//        used[v] = 1;
//        sum += dist[v];
//
//        printf("%d", v);
//        if (k < n) printf(" ");
//
//        // dist 갱신 (간선이 있고, 아직 선택 안 됐을 때)
//        for (int u = 1; u <= n; u++) {
//            if (!used[u] && w[v][u] > 0) {
//                if (dist[u] == -1 || w[v][u] < dist[u])
//                    dist[u] = w[v][u];
//            }
//        }
//    }
//
//    printf("\n%d\n", sum);
//    return 0;
//}