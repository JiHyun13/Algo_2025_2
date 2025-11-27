//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//int M, n, q, * T;
//
//int h1(int x);
//int h2(int x);
//void insert(int x);
//void search(int x);
//void print();
//
//int main() {
//    scanf("%d %d %d", &M, &n, &q);
//    T = (int*)calloc(M, sizeof(int));
//    char c; int x;
//    while (1) {
//        scanf(" %c", &c);
//        if (c == 'e') { print(); break; }
//        if (c == 'i') { scanf("%d", &x); insert(x); }
//        else if (c == 's') { scanf("%d", &x); search(x); }
//        else if (c == 'p') print();
//    }
//    free(T);
//    return 0;
//}
//
//int h1(int x) { return x % M; }
//int h2(int x) { return q - (x % q); }
//
//void insert(int x) {
//    int i = h1(x), d = h2(x);
//    while (T[i] != 0) { printf("C"); i = (i + d) % M; }
//    T[i] = x;
//    printf("%d\n", i);
//}
//
//void search(int x) {
//    int i = h1(x), d = h2(x), start = i;
//    while (T[i] != 0) {
//        if (T[i] == x) { printf("%d %d\n", i, T[i]); return; }
//        i = (i + d) % M;
//        if (i == start) break;
//    }
//    printf("-1\n");
//}
//
//void print() {
//    for (int i = 0; i < M; i++) printf("%d ", T[i]);
//    printf("\n");
//}
