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
//    Node* head = makeList(n); //1. ����Ʈ �����
//    head = mergeSort(head); //sort �ؼ� ����@
//    printList(head); //���
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
//    if (!head || !head->next) return head; //0��, 1����� �׳� ���� / ����������
//    Node* a, * b; //���⿡ �ݹ� ������
//    partition(head, &a, &b);
//    return merge(mergeSort(a), mergeSort(b)); //��� �ݹ�....->�������� ���ļ� ����
//}
//
//Node* merge(Node* a, Node* b) { //a�� b�� �������� ���ؼ� ��ġ�°���. 
//    if (a == NULL) return b; // ������ �� ������ �ٸ� �� �ʿ� ���� ����Ǿ��ִٴ� ��...
//    if (b == NULL) return a;
//
//    Node* p = NULL; //��ĥ��
//    if (a->data < b->data) {
//        p = a;
//        p->next = merge(a->next, b); //������ ������ �̾���ϰ����ϱ�/
//    }
//    else {
//        p = b;
//        p->next = merge(a, b->next);
//    }
//    return p;
//}
//void partition(Node* head, Node** a, Node** b) { //�տ� a �� b  
//    Node* slow = head, * fast = head->next; 
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    *a = head;
//    *b = slow->next; //~slow ������ ��.
//    slow->next = NULL;
//}
//
//void printList(Node* head) {
//    while (head) {
//        printf(" %d", head->data);
//        head = head->next;
//    }
//}
