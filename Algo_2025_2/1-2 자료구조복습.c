//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma warning(disable:4996)
//
//typedef struct Node {
//	int id;
//	struct Node* left;
//	struct Node* right;
//} Node;
//
//Node* makeNode(int n);
//void traverse(Node* root, char* path);
//
//int main() {
//	int n;
//	scanf("%d", &n);
//
//	Node* root = NULL;
//	Node* tree[1001] = { NULL };
//
//	for (int i = 0; i < n; i++) {
//		int id, l, r;
//		scanf("%d %d %d", &id, &l, &r);
//
//		if (!tree[id]) tree[id] = makeNode(id);
//		Node* cur = tree[id];
//		if (i == 0) root = cur;
//
//		if (l != 0) {
//			if (!tree[l]) tree[l] = makeNode(l);
//			cur->left = tree[l];
//		}
//		if (r != 0) {
//			if (!tree[r]) tree[r] = makeNode(r);
//			cur->right = tree[r];
//		}
//	}
//
//	int s;
//	scanf("%d", &s);
//	for (int i = 0; i < s; i++) {
//		char path[101];
//		scanf("%s", path);
//		traverse(root, path);
//	}
//
//
//
//
//	return 0;
//}
//
//Node* makeNode(int id) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->id = id;
//	node->left = NULL;
//	node->right = NULL;
//	return node;
//}
//
//void traverse(Node* root, char* path) {
//	Node* current = root;
//	printf("%d", current->id);
//
//	for (int i = 0; path[i] != '\0'; i++) {
//		if (path[i] == 'L' && current->left) {
//			current = current->left;
//			printf(" %d", current->id);
//		}
//		else if (path[i] == 'R' && current->right) {
//			current = current->right;
//			printf(" %d", current->id);
//		}
//		else {
//			break;
//		}
//	}
//	printf("\n");
//}