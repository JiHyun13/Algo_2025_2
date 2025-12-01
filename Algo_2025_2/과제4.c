//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define N 100 //그래프 정점 전체가 100개라고 가정함.
//
//typedef struct Node { //정점
//    int v, w; //한 정점 당 간선 2개 씩
//    struct Node* n; //해당 정점의 위치를 가르키는 포인터
//} Node;
//
//Node* g[N]; //전체 그래프
//int dist[N], cnt[N], vis[N]; //최단거리, 최단경로 수, 방문완료체크
//
//void add(int a, int b, int w);
//void dijk(int s, int t);
//
//
//int main() {
//    // A 연결
//    add(0, 1, 8); add(1, 0, 8);
//    add(0, 2, 1); add(2, 0, 1);
//    add(0, 3, 4); add(3, 0, 4);
//    //B 연결
//    add(1, 2, 7); add(2, 1, 7);
//    add(1, 4, 4); add(4, 1, 4);
//    //C 연결
//    add(2, 3, 5); add(3, 2, 5);
//    add(2, 4, 3); add(4, 2, 3);
//    add(2, 5, 9); add(5, 2, 9);
//    //D 연결
//    add(3, 5, 4); add(5, 3, 4);
//
//    char s[5], t[5];
//    //0 0 입력시 종료! 과제에 나온대로 공백 처리가 scanf에서 잘 안돼서 0 0 으로 바꿈.
//    printf("source, target 최단거리 최단경로 수\n");
//
//    while (1) {
//        scanf("%s %s", s, t);
//        if (s[0] == '0' && t[0] == '0') return 0;
//
//        int a = s[0] - 'A';
//        int b = t[0] - 'A';
//        dijk(a, b); //정점은 A를 뺀 숫자 형태로 dijk 에 넣어줌.
//        
//        printf("%s %s %d %d\n", s, t, dist[b], cnt[b]); 
//    }
//    return 0;
//}
//
//// 간선 추가 함수 
//void add(int a, int b, int w) {
//    Node* p = malloc(sizeof(Node));
//    p->v = b; p->w = w; p->n = g[a]; //연결된 v,w에 가중치 값 넣고 n에 현재 위치 저장
//    g[a] = p; //a번째에 p 정점 정보 저장
//}
//
//void dijk(int s, int t) {
//    //전체적으로 초기화.
//    for (int i = 0; i < N; i++) {
//        dist[i] = -1;   // -1이면 아직 거리 모름
//        cnt[i] = 0; 
//        vis[i] = 0; //0이면 미방문
//    }
//
//    dist[s] = 0; //S에 대한 초기화. 거리는 0으로,
//    cnt[s] = 1; //최소한 경로 수가 1개는 있다
//
//    for (int k = 0; k < N; k++) { //그래프 전체를 순회하며..
//        int x = -1;
//
//        // 아직 안 쓴 정점 중 dist가 가장 작은 것 고르기
//        for (int i = 0; i < N; i++) {
//            if (!vis[i] && dist[i] != -1) {
//                if (x == -1 || dist[i] < dist[x]) x = i;
//            }
//        }
//
//        if (x == -1) break; //아무것도 선택 안됐으면? 다 정점 본거라서 멈춤
//        vis[x] = 1;//x 선택됐으면 방문했다고 체크
//        if (x == t) break; // 목적지면 굳이 더 안 돎
//
//        // 인접 정점 갱신
//        for (Node* p = g[x]; p; p = p->n) {
//            int y = p->v, w = p->w;
//            int nd = dist[x] + w;
//
//            // 1. 처음 방문했다면
//            if (dist[y] == -1) {
//                dist[y] = nd;
//                cnt[y] = cnt[x]; // 새로운 최단 경로 개수는 x의 개수
//            }
//            // 2. 더 짧은 거리 찾음 -> 최단 거리 dist 갱신 + 경로수 바꿈
//            else if (nd < dist[y]) {
//                dist[y] = nd;
//                cnt[y] = cnt[x]; // 새로운 최단 경로 개수는 x의 개수
//            }
//            // 3. 같은 거리면 경로 수 추가 -> 최단 경로 개수 cnt 누적 
//            else if (nd == dist[y]) {
//                cnt[y] += cnt[x]; // 기존 경로 개수에 x를 거쳐오는 경로 개수를 더함
//            }
//        }
//    }
//}