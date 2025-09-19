//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning(disable:4996)
//
//// 노드 구조체 정의
//typedef struct Node {
//    char data;
//    struct Node* prev;
//    struct Node* next;
//} Node;
//
//// 이중연결리스트
//typedef struct List {
//    Node* head;
//    Node* tail;
//    int size;
//} List;
//
//void init(List* list) {
//    //전부 null로 초기화
//    list->head = NULL;
//    list->tail = NULL;
//    list->size = 0;
//}
//
//Node* create(char data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//
//    newNode->data = data;
//    newNode->prev = NULL;
//    newNode->next = NULL;
//    return newNode;
//}
//
//// 순위 r에 원소 e 추가
//void add(List* list, int r, char e) {
//    if (r < 1 || r > list->size + 1) {
//        printf("invalid position\n");
//        return;
//    }
//    Node* newNode = create(e);
//    if (r == 1) { //맨 앞에 요소 추가
//        newNode->next = list->head;
//        if (list->head) list->head->prev = newNode;
//        list->head = newNode;
//        if (list->size == 0) list->tail = newNode;
//    }
//    else {
//        Node* current = list->head;
//        for (int i = 1; i < r - 1; i++) {
//            current = current->next;
//        }
//        newNode->next = current->next;
//        newNode->prev = current;
//        if (current->next) current->next->prev = newNode;
//        current->next = newNode;
//        if (r == list->size + 1) list->tail = newNode;
//    }
//    list->size++;
//}
//
//// 순위 r에 위치한 원소 삭제
//void delete(List* list, int r) {
//    if (r < 1 || r > list->size) {
//        printf("invalid position\n");
//        return;
//    }
//    Node* current = list->head;
//    for (int i = 1; i < r; i++) {
//        current = current->next;
//    }
//    if (current->prev) current->prev->next = current->next;
//    else list->head = current->next;
//    if (current->next) current->next->prev = current->prev;
//    else list->tail = current->prev;
//    free(current);
//    list->size--;
//}
//
//// 순위 r에 위치한 원소 반환
//int get(List* list, int r) {
//    if (r < 1 || r > list->size) {
//        printf("invalid position\n");
//        return -1;
//    }
//    Node* current = list->head;
//    for (int i = 1; i < r; i++) {
//        current = current->next;
//    }
//    return current->data;
//}
//
//// 리스트 출력
//void print(List* list) {
//    Node* current = list->head;
//    while (current) {
//        printf("%c", current->data);
//        current = current->next;
//    }
//    printf("\n");
//}
//
//int main() {
//    int N, a;
//    char c, b;
//    List list;
//
//    scanf("%d", &N);
//    init(&list);
//
//    for (int i = 0; i < N; i++) {
//        scanf(" %c", &c);
//        if (c == 'A') {
//            scanf("%d %c", &a, &b);
//            add(&list, a, b);
//        }
//        else if (c == 'D') {
//            scanf("%d", &a);
//            delete(&list, a);
//        }
//        else if (c == 'G') {
//            scanf("%d", &a);
//            int n = get(&list, a);
//            if (n != -1) printf("%c\n", n);
//        }
//        else if (c == 'P') {
//            print(&list);
//        }
//    }
//
//    return 0;
//}
