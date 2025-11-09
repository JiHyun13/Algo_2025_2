//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//	int key, height;
//	struct Node* left, * right, * parent;
//} Node;
//
//Node* root = NULL;
//
//Node* treeSearch(Node* node, int k);
//Node* insertItem(Node* node, int k, Node* parent);
//int findElement(int k);
//int getHeight(Node* n);
//void updateHeight(Node* n);
//int getBalance(Node* n);
//Node* rotateRight(Node* y);
//Node* rotateLeft(Node* x);
//Node* rebalance(Node* node);
//void printTree(Node* node);
//
//int main() {
//	char menu;
//	int k;
//	while (1) {
//		scanf(" %c", &menu);
//		if (menu == 'i') {
//			scanf("%d", &k);
//			root = insertItem(root, k, NULL);
//		}
//		else if (menu == 's') {
//			scanf("%d", &k);
//			int res = findElement(k);
//			if (res == -1) printf("X\n");
//			else printf("%d\n", res);
//		}
//		else if (menu == 'p') {
//			printTree(root);
//			printf("\n");
//		}
//		else if (menu == 'q') break;
//	}
//	return 0;
//}
//
//Node* treeSearch(Node* node, int k) {
//	if (node == NULL || node->key == k)
//		return node;
//	else if (k < node->key)
//		return treeSearch(node->left, k);
//	else
//		return treeSearch(node->right, k);
//}
//
//int findElement(int k) {
//	Node* n = treeSearch(root, k);
//	if (n == NULL) return -1;
//	else return n->key;
//}
//
//Node* insertItem(Node* node, int k, Node* parent) {
//	if (node == NULL) {
//		Node* newNode = (Node*)malloc(sizeof(Node));
//		newNode->key = k;
//		newNode->left = newNode->right = NULL;
//		newNode->parent = parent;
//		newNode->height = 1;
//		return newNode;
//	}
//	if (k < node->key)
//		node->left = insertItem(node->left, k, node);
//	else if (k > node->key)
//		node->right = insertItem(node->right, k, node);
//	else
//		return node; // 중복 방지
//	return rebalance(node);
//}
//
//int getHeight(Node* n) {
//	return n ? n->height : 0;
//}
//
//void updateHeight(Node* n) {
//	int lh = getHeight(n->left), rh = getHeight(n->right);
//	n->height = 1 + (lh > rh ? lh : rh);
//}
//
//int getBalance(Node* n) {
//	return getHeight(n->left) - getHeight(n->right);
//}
//
//Node* rotateRight(Node* y) {
//	Node* x = y->left;
//	y->left = x->right;
//	if (x->right) x->right->parent = y;
//	x->right = y;
//	x->parent = y->parent;
//	y->parent = x;
//	updateHeight(y);
//	updateHeight(x);
//	return x;
//}
//
//Node* rotateLeft(Node* x) {
//	Node* y = x->right;
//	x->right = y->left;
//	if (y->left) y->left->parent = x;
//	y->left = x;
//	y->parent = x->parent;
//	x->parent = y;
//	updateHeight(x);
//	updateHeight(y);
//	return y;
//}
//
//Node* rebalance(Node* node) {
//	updateHeight(node);
//	int balance = getBalance(node);
//
//	if (balance > 1) {
//		if (getBalance(node->left) < 0)
//			node->left = rotateLeft(node->left);
//		return rotateRight(node);
//	}
//	else if (balance < -1) {
//		if (getBalance(node->right) > 0)
//			node->right = rotateRight(node->right);
//		return rotateLeft(node);
//	}
//	return node;
//}
//
//void printTree(Node* node) {
//	if (node == NULL) return;
//	printf(" %d", node->key);
//	printTree(node->left);
//	printTree(node->right);
//}