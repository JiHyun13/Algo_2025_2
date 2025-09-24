//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct Node{
//	int item;
//	struct Node* next;
//}Node;
//
//Node* makeList(int n);
//Node* mergeSort(Node* L);
//Node* merge(Node* L1, Node* L2);
//void partiton(Node* L, Node** L1, Node** L2);
//
//int main() {
//
//	int N;
//	scanf("%d ", &N);
//
//	Node* L = makeList(N);
//	
//	L = mergeSort(L); //합병 정렬하여 오름차순 출력
//	for (Node* p = L; p != NULL; p=p->next) {
//		printf("%d ", p->item);
//	}
//}
//
//Node* makeList(int N) {
//	Node* head = NULL;
//	Node* tail = NULL;
//
//	for (int i = 0; i < N; i++) {
//		Node* newNode = (Node*)malloc(sizeof(Node));
//		newNode->next = NULL;
//		scanf("%d", &newNode->item);
//
//		if (head == NULL) {
//			head = newNode;
//			tail = newNode;
//		}
//		else {
//			tail->next = newNode;
//			tail = newNode;
//		}
//	}
//	return head;
//}
//
//Node* mergeSort(Node* L) {
//	if (L == NULL || L->next == NULL) return L; //1개로 쪼개졌을 경우 return
//
//	Node* L1=NULL, * L2=NULL;
//	partiton(L, &L1, &L2); //L을 L1,L2로 분리
//
//	L1 = mergeSort(L1); //L1을 분리
//	L2 = mergeSort(L2); //L2를 분리
//
//	return merge(L1, L2); //전부 반환돼서 L1과 L2에 값이 하나씩 들어오면 merge
//}
//
//Node* merge(Node* L1, Node* L2) {
//	if (L1 == NULL) return L2;
//	if (L2 == NULL) return L1;
//
//	Node* p;
//	
//	//오름차순
//	if (L1->item <= L2->item) {
//		p = L1;
//		p->next = merge(L1->next, L2);
//	}
//	else {
//		p = L2;
//		p->next = merge(L1, L2->next);
//	}
//
//	return p;
//}
//
//void partiton(Node* L, Node** L1, Node** L2) {
//	
//	//slow&fast 방법. slow가 딱 절반.
//	Node* slow = L;
//	Node* fast = L->next;
//
//	while (fast != NULL) {
//		fast = fast->next;
//		if (fast != NULL) {
//			slow = slow->next;
//			fast = fast->next;
//		}
//	}
//
//	*L1 = L;
//	*L2 = slow->next;
//	slow->next = NULL;
//}
//
