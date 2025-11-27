//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    int a, b, w;
//} E;
//
//E e[1005];
//int p[105];
//int n, m;
//
//// 부모 찾기 (경로압축)
//int find(int x) {
//    if (p[x] == x) return x;
//    return p[x] = find(p[x]);
//}
//
//// union
//int merge(int a, int b) {
//    a = find(a); b = find(b);
//    if (a == b) return 0;
//    p[b] = a;
//    return 1;
//}
//
//// 정렬용
//int cmp(const void* x, const void* y) {
//    return ((E*)x)->w - ((E*)y)->w;
//}
//
//int main() {
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < m; i++)
//        scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].w);
//
//    // 분리집합 초기화
//    for (int i = 1; i <= n; i++) p[i] = i;
//
//    qsort(e, m, sizeof(E), cmp);
//
//    int sum = 0, cnt = 0;
//
//    for (int i = 0; i < m; i++) {
//        if (merge(e[i].a, e[i].b)) {
//            // 간선 선택
//            printf("%d", e[i].w);
//            cnt++;
//            sum += e[i].w;
//
//            if (cnt < n - 1) printf(" ");
//            else printf("\n");
//        }
//    }
//
//    printf("%d\n", sum);
//    return 0;
//}
