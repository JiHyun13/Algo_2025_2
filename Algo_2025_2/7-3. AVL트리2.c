#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key, height;
	struct Node* left, * right, * parent;
} Node;

Node* root = NULL;

Node* treeSearch(Node* w, int k);
int isExternal(Node* w);
int isInternal(Node* w);
void expandExternal(Node* w);
void updateHeight(Node* w);
int getHeight(Node* w);
int isBalanced(Node* w);
int getBalance(Node* w);
Node* restructure(Node* x, Node* y, Node* z);
void searchAndFixAfterInsertion(Node* w);
Node* inOrderSucc(Node* w);
Node* reduceExternal(Node* z);
void searchAndFixAfterRemoval(Node* w);
void insertItem(int k);
int removeElement(int k);
int findElement(int k);
void printTree(Node* w);

int main() {
	char menu;
	int k;

	root = (Node*)malloc(sizeof(Node));
	root->left = root->right = root->parent = NULL;
	root->height = 0;

	while (1) {
		scanf(" %c", &menu);
		if (menu == 'i') {
			scanf("%d", &k);
			insertItem(k);
		}
		else if (menu == 'd') {
			scanf("%d", &k);
			int res = removeElement(k);
			if (res == -1) printf("X\n");
			else printf("%d\n", res);
		}
		else if (menu == 's') {
			scanf("%d", &k);
			int res = findElement(k);
			if (res == -1) printf("X\n");
			else printf("%d\n", res);
		}
		else if (menu == 'p') {
			printTree(root);
			printf("\n");
		}
		else if (menu == 'q') break;
	}
	return 0;
}

int isExternal(Node* w) {
	return (w->left == NULL && w->right == NULL);
}

int isInternal(Node* w) {
	return (w->left != NULL || w->right != NULL);
}

Node* treeSearch(Node* w, int k) {
	if (isExternal(w)) return w; 
	if (k == w->key) return w;   
	if (k < w->key) return treeSearch(w->left, k);  // ���� Ž��
	else return treeSearch(w->right, k);             // ������ Ž��
}

void expandExternal(Node* w) {
	Node* l = (Node*)malloc(sizeof(Node));
	Node* r = (Node*)malloc(sizeof(Node));
	l->left = l->right = NULL;
	l->parent = w;
	l->height = 0;
	r->left = r->right = NULL;
	r->parent = w;
	r->height = 0;
	w->left = l;
	w->right = r;
	w->height = 1;
}

int getHeight(Node* w) {
	return w ? w->height : 0;
}

void updateHeight(Node* w) {
	if (isExternal(w)) w->height = 0;
	else {
		int hL = getHeight(w->left), hR = getHeight(w->right);
		w->height = (hL > hR ? hL : hR) + 1; // ū �� +1
	}
}

int getBalance(Node* w) {
	return getHeight(w->left) - getHeight(w->right);
}

int isBalanced(Node* w) {
	int bf = getBalance(w);
	return (bf >= -1 && bf <= 1);
}

Node* restructure(Node* x, Node* y, Node* z) {
	Node* a; Node* b; Node* c;
	Node* T0; Node* T1; Node* T2; Node* T3;

	if (y == z->left && x == y->left) { // LL
		a = x; b = y; c = z;
		T0 = a->left; T1 = a->right;
		T2 = y->right; T3 = z->right;
	}
	else if (y == z->left && x == y->right) { // LR
		a = y; b = x; c = z;
		T0 = a->left; T1 = x->left;
		T2 = x->right; T3 = z->right;
	}
	else if (y == z->right && x == y->right) { // RR
		a = z; b = y; c = x;
		T0 = z->left; T1 = y->left;
		T2 = x->left; T3 = x->right;
	}
	else { // RL
		a = z; b = x; c = y;
		T0 = z->left; T1 = x->left;
		T2 = x->right; T3 = y->right;
	}

	// �θ� ���� ����
	if (z->parent == NULL) root = b;
	else {
		if (z == z->parent->left) z->parent->left = b;
		else z->parent->right = b;
	}
	b->parent = z->parent;
	a->left = T0; if (T0) T0->parent = a;
	a->right = T1; if (T1) T1->parent = a;
	c->left = T2; if (T2) T2->parent = c;
	c->right = T3; if (T3) T3->parent = c;
	b->left = a; b->right = c;
	a->parent = b; c->parent = b;

	updateHeight(a);
	updateHeight(c);
	updateHeight(b);
	return b;
}

void searchAndFixAfterInsertion(Node* w) {
	w = w->parent;
	while (w != NULL) {
		updateHeight(w);
		if (!isBalanced(w)) { 
			Node* z = w;
			Node* y = (getHeight(z->left) >= getHeight(z->right)) ? z->left : z->right;
			Node* x = (getHeight(y->left) >= getHeight(y->right)) ? y->left : y->right;
			restructure(x, y, z);
			break;
		}
		w = w->parent; // ���� �̵�
	}
}

void insertItem(int k) {
	Node* w = treeSearch(root, k);
	if (isInternal(w)) return; 
	w->key = k;
	expandExternal(w); 
	searchAndFixAfterInsertion(w); // ���� ����
}

Node* inOrderSucc(Node* w) {
	w = w->right;
	while (isInternal(w->left)) w = w->left; // ���� ������
	return w;
}

Node* reduceExternal(Node* z) {
	// �ܺγ�� ����
	Node* w = z->parent;
	Node* zs;
	if (z == w->left) zs = w->right;
	else zs = w->left;

	if (w == root) {
		root = zs; zs->parent = NULL;
	}
	else {
		Node* g = w->parent;
		if (w == g->left) g->left = zs;
		else g->right = zs;
		zs->parent = g;
	}
	free(z);
	free(w);
	return zs; // �ܿ� ����Ʈ�� ��ȯ
}

void searchAndFixAfterRemoval(Node* w) {
	while (w != NULL) {
		updateHeight(w);
		if (!isBalanced(w)) { // �ұ���
			Node* z = w;
			Node* y = (getHeight(z->left) >= getHeight(z->right)) ? z->left : z->right;
			Node* x = (getHeight(y->left) >= getHeight(y->right)) ? y->left : y->right;
			w = restructure(x, y, z);
		}
		if (w->parent == NULL) break; // ��Ʈ ����
		else w = w->parent;
	}
}

int removeElement(int k) {
	Node* w = treeSearch(root, k);
	if (isExternal(w)) return -1; 
	int deleted = w->key;
	Node* z = w->left;
	if (!isExternal(z)) z = w->right; // �ڽ� ����
	Node* zs;
	if (isExternal(z)) zs = reduceExternal(z); // �ܺγ�� ����
	else {
		Node* y = inOrderSucc(w); // �İ�
		w->key = y->key;
		z = y->left;
		zs = reduceExternal(z);
	}
	searchAndFixAfterRemoval(zs->parent); // ���� ����
	return deleted;
}

int findElement(int k) {
	Node* w = treeSearch(root, k);
	if (isExternal(w)) return -1; 
	return w->key;
}

void printTree(Node* w) {
	if (isExternal(w)) return;
	printf(" %d", w->key); 
	printTree(w->left);
	printTree(w->right);
}
