//#include <stdio.h>
//#include <stdlib.h>
//
//// 최대 정점 개수 100 + 1 
//#define MAX_N 101 
//
//#define QUEUE_SIZE MAX_N
//int queue[QUEUE_SIZE]; 
//int front = 0; 
//int rear = 0;
//
//int N, M, S; // 정점 개수, 간선 개수, 시작 정점
//int visited[MAX_N] = { 0, }; // 0: 미방문, 1: 방문
//
//
//// 인접 리스트 구조체
//typedef struct {
//    int count;
//    int neighbors[MAX_N];
//} AdjList;
//
//AdjList adj_list[MAX_N];
//
//
//void enqueue(int item) {
//    if (rear < QUEUE_SIZE) {
//        queue[rear++] = item;
//    }
//}
//
//int dequeue() {
//    if (front < rear) {
//        return queue[front++];
//    }
//    return -1; 
//}
//
//int is_queue_empty() {
//    return (front == rear);
//}
//
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//void BFS(int start) {
//    // 1. 시작 정점을 방문 처리하고 큐에 삽입
//    visited[start] = 1;
//    enqueue(start);
//    printf("%d\n", start);
//
//    // 2. 큐가 빌 때까지 반복
//    while (!is_queue_empty()) {
//        int u = dequeue(); // 큐에서 정점을 꺼냄
//
//        // 3. 인접 정점 순회
//        for (int i = 0; i < adj_list[u].count; i++) {
//            int w = adj_list[u].neighbors[i];
//
//            // 4. 방문 처리,큐에 삽입
//            if (visited[w] == 0) {
//                visited[w] = 1;
//                printf("%d\n", w);
//                enqueue(w);
//            }
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
//    for (int i = 1; i <= N; i++) {
//        if (adj_list[i].count > 0) {
//            qsort(adj_list[i].neighbors, adj_list[i].count, sizeof(int), compare);
//        }
//    }
//
//    BFS(S);
//
//    return 0;
//}