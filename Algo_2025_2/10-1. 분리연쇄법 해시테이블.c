//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//    int key;
//    struct Node* next;
//} Node;
//
//int M;
//Node** T;
//
//int h(int x);
//void insert(int x);
//int search(int x);
//int del(int x);
//void print();
//
//int main() {
//    scanf("%d", &M);
//    T = (Node**)calloc(M, sizeof(Node*));
//    char c; int x;
//    while (1) {
//        scanf(" %c", &c);
//        if (c == 'e') break;
//        if (c == 'i') { scanf("%d", &x); insert(x); }
//        else if (c == 's') { scanf("%d", &x); printf("%d\n", search(x)); }
//        else if (c == 'd') { scanf("%d", &x); printf("%d\n", del(x)); }
//        else if (c == 'p') print();
//    }
//    return 0;
//}
//
//int h(int x) { return x % M; }
//
//void insert(int x) {
//    int i = h(x);
//    Node* n = (Node*)malloc(sizeof(Node));
//    n->key = x;
//    n->next = T[i]; // ¾Õ¿¡ »ðÀÔ
//    T[i] = n;
//}
//
//int search(int x) {
//    int i = h(x), pos = 1;
//    Node* p = T[i];
//    while (p) {
//        if (p->key == x) return pos;
//        p = p->next; pos++;
//    }
//    return 0;
//}
//
//int del(int x) {
//    int i = h(x), pos = 1;
//    Node* p = T[i], * prev = NULL;
//    while (p) {
//        if (p->key == x) {
//            if (prev) prev->next = p->next;
//            else T[i] = p->next;
//            free(p);
//            return pos;
//        }
//        prev = p; p = p->next; pos++;
//    }
//    return 0;
//}
//
//void print() {
//    for (int i = 0; i < M; i++) {
//        Node* p = T[i];
//        while (p) { printf("%d ", p->key); p = p->next; }
//    }
//    printf("\n");
//}
