//#include <stdio.h>
//#include <stdlib.h> 
//
//// 최대 정점 개수 100 + 1 
//#define MAX_N 101 
//
//int N, M, S; // 정점 개수, 간선 개수, 시작 정점
//int visited[MAX_N] = { 0, };
//
//
//typedef struct {
//    int count;
//    int neighbors[MAX_N];
//} AdjList;
//
//AdjList adj_list[MAX_N];
//
//
//// 비교
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//void DFS(int u) {
//    // 1. 현재 정점 방문 처리
//    visited[u] = 1;
//    printf("%d\n", u);
//
//    // 2. 인접 정점 순회
//    for (int i = 0; i < adj_list[u].count; i++) {
//        int w = adj_list[u].neighbors[i];
//
//        // 3. 방문x면 재귀
//        if (visited[w] == 0) {
//            DFS(w);
//        }
//    }
//}
//
//
//int main() {
//    if (scanf("%d %d %d", &N, &M, &S) != 3) {
//        return 1;
//    }
//
//    for (int i = 1; i <= N; i++) {
//        adj_list[i].count = 0;
//    }
//
//    for (int i = 0; i < M; i++) {
//        int u, v;
//        scanf("%d %d", &u, &v);
//
//        // u -> v
//        adj_list[u].neighbors[adj_list[u].count] = v;
//        adj_list[u].count++;
//
//        // v -> u
//        adj_list[v].neighbors[adj_list[v].count] = u;
//        adj_list[v].count++;
//    }
//
//    //  정렬
//    for (int i = 1; i <= N; i++) {
//        if (adj_list[i].count > 0) {
//            //qsort
//            qsort(adj_list[i].neighbors, adj_list[i].count, sizeof(int), compare);
//        }
//    }
//
//    DFS(S);
//
//    return 0;
//}