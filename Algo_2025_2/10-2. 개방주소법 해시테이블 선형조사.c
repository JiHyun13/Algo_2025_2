//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//int M, n, * T;
//
//int h(int x);
//void insert(int x);
//void search(int x);
//
//int main() {
//    scanf("%d %d", &M, &n);
//    T = (int*)calloc(M, sizeof(int));
//    char c; int x;
//    while (1) {
//        scanf(" %c", &c);
//        if (c == 'e') break;
//        if (c == 'i') { scanf("%d", &x); insert(x); }
//        else if (c == 's') { scanf("%d", &x); search(x); }
//    }
//    free(T);
//    return 0;
//}
//
//int h(int x) { return x % M; }
//
//void insert(int x) {
//    int i = h(x);
//    while (T[i] != 0) { printf("C"); i = (i + 1) % M; }
//    T[i] = x;
//    printf("%d\n", i);
//}
//
//void search(int x) {
//    int i = h(x), start = i;
//    while (T[i] != 0) {
//        if (T[i] == x) { printf("%d %d\n", i, T[i]); return; }
//        i = (i + 1) % M;
//        if (i == start) break;
//    }
//    printf("-1\n");
//}
