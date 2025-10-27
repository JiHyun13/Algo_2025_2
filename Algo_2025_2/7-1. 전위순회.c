//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//	int key;
//	struct Node* left, *right, *parent;
//}Node;
//
//Node * root = NULL;
//
//int findElement(int k);
//void insertItem(int k);
//Node* treeSearch(Node* node,int k);
//int removeElement(int k);
//Node* inOrderSucc(Node* node);
//void printTree(Node* node);
//
//int main() {
//	char menu;
//	int k;
//
//	while (1) {
//		scanf("%c", &menu);
//		if (menu == 'i') {
//			scanf("%d", &k);
//			insertItem(k);
//		}
//		else if (menu == 'd') {
//			scanf("%d", &k);
//			k = removeElement(k);
//			if (k == -1) printf("X\n");
//			else printf("%d\n", k);
//		}
//		else if (menu == 's') {
//			scanf("%d", &k);
//			k = findElement(k);
//			if (k == -1) printf("X\n");
//			else printf("%d\n", k);
//		}
//		else if (menu == 'p') {
//			printTree(root);
//			printf("\n");
//		}
//		else if (menu == 'q') break;
//	}
//}
//
//int findElement(int k) {
//	Node* n = treeSearch(root, k);
//	if (n == NULL) return -1; //원소 반환 못함
//	else return n->key;
//}
//void insertItem(int k) {
//	Node* p = NULL;
//	Node* n = root;
//
//	// null일 때까지 밀기.
//	while (n != NULL) {
//		p = n;
//		if (k < n->key)
//			n = n->left;
//		else if (k > n->key)
//			n = n->right;
//	}
//
//	// 새 노드 하나 만들어서 root/left/right
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->key = k;
//	newNode->left = newNode->right = NULL;
//	newNode->parent = p;
//
//	if (p == NULL) root = newNode; 
//	else if (k < p->key) p->left = newNode;
//	else p->right = newNode;
//}
//Node* treeSearch(Node* node,int k) {
//	if (node == NULL || node->key == k)
//		return node;
//	else if (k < node->key)
//		return treeSearch(node->left, k);
//	else
//		return treeSearch(node->right, k);
//}
//int removeElement(int k) {
//	Node* n = treeSearch(root, k);
//	if (n == NULL) return -1;
//
//	int deletedKey = n->key;
//
//	if (n->left != NULL && n->right != NULL) { //중위순위 찾아서 n교체
//		Node* succ = inOrderSucc(n);
//		n->key = succ->key;
//		n = succ;
//	}
//	//기존 n parent 를 이어줌.
//	Node* child = (n->left != NULL) ? n->left : n->right;
//	if (child != NULL)
//		child->parent = n->parent;
//
//	if (n->parent == NULL)
//		root = child;
//	else if (n == n->parent->left)
//		n->parent->left = child;
//	else
//		n->parent->right = child;
//
//	free(n);
//	return deletedKey;
//}
//
//Node* inOrderSucc(Node* node) {
//	Node* curr = node->right;
//	while (curr && curr->left)
//		curr = curr->left;
//	return curr; //왼쪽끝
//}
//void printTree(Node* node) {
//	if (node == NULL) return;
//	printf(" %d", node->key);
//	printTree(node->left);
//	printTree(node->right);
//}