//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct Node {
//    int data;
//    struct Node* next;
//}Node;
//
//Node* makeList(int n);
//Node* mergeSort(Node* head);
//Node* merge(Node* a, Node* b);
//void partition(Node* head, Node** a, Node** b);
//void printList(Node* head);
//
//int main() {
//
//    int n;
//    scanf("%d", &n);
//    Node* head = makeList(n); //1. 리스트 만들기
//    head = mergeSort(head); //sort 해서 저장@
//    printList(head); //출력
//    return 0;
//}
//Node* makeList(int n) {
//    Node* head = NULL;
//    for (int i = 0; i < n; i++) {
//        Node* newNode = (Node*)malloc(sizeof(Node));
//        scanf(" %d", &newNode->data);
//        newNode->next = head;
//        head = newNode;
//    }
//    return head;
//}
//
//Node* mergeSort(Node* head) {
//    if (!head || !head->next) return head; //0개, 1개라면 그냥 리턴 / 기저조건임
//    Node* a, * b; //여기에 반반 나누기
//    partition(head, &a, &b);
//    return merge(mergeSort(a), mergeSort(b)); //계속 반반....->마지막에 합쳐서 리턴
//}
//
//Node* merge(Node* a, Node* b) { //a랑 b랑 차곡차곡 비교해서 합치는거임. 
//    if (a == NULL) return b; // 한쪽을 다 썼으면 다른 한 쪽에 값이 저장되어있다는 뜻...
//    if (b == NULL) return a;
//
//    Node* p = NULL; //합칠거
//    if (a->data < b->data) {
//        p = a;
//        p->next = merge(a->next, b); //작은거 다음에 이어붙일거정하기/
//    }
//    else {
//        p = b;
//        p->next = merge(a, b->next);
//    }
//    return p;
//}
//void partition(Node* head, Node** a, Node** b) { //앞에 a 뒤 b  
//    Node* slow = head, * fast = head->next; 
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    *a = head;
//    *b = slow->next; //~slow 까지는 앞.
//    slow->next = NULL;
//}
//
//void printList(Node* head) {
//    while (head) {
//        printf(" %d", head->data);
//        head = head->next;
//    }
//}
