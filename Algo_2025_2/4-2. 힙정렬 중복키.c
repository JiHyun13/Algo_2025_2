#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int H[100];
int n = 0;

void insertItem(int key);
void upHeap(int i);
void downHeap(int i);
void inPlaceHeapSort();
void rBuildHeap(int i);
void buildHeap();
void printArray();

int main() {

	int N, key;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &key);
		insertItem(key);
	}

	inPlaceHeapSort();
	printArray();
}

void insertItem(int key) {
	if (n > 100) return;
	H[++n] = key;
	upHeap(n);
}

void upHeap(int i) {
	while (i > 1) {
		int p = i / 2;
		if (H[p] >= H[i]) break;
		int tmp = H[p]; H[p] = H[i]; H[i] = tmp;
		i = p;
	}
}

void downHeap(int i) {
	while (1) {
		int left = i * 2;
		int right = i * 2 + 1;
		int t = i;
		if (left <= n && H[left] >= H[t]) t = left; //중복처리 >=
		if (right <= n && H[right] >= H[t]) t = right; //중복처리 >=
		if (t == i) break; //교환안되면 멈춤

		int tmp = H[t]; H[t] = H[i]; H[i] = tmp;
		i = t;
	}
}

void inPlaceHeapSort() {

	int N = n;

	buildHeap();

	for (int i = n; i >= 2; i--) {
		int tmp = H[1]; H[1] = H[i]; H[i] = tmp;
		n--;
		downHeap(1);
	}

	n = N;
}

void printArray() {
	for (int i = 1; i <= n; i++) printf(" %d", H[i]);
}

void rBuildHeap(int i) {
	if (i < n) return;
	rBuildHeap(i * 2);
	rBuildHeap(i * 2 + 1);
	downHeap(i);
}

void buildHeap() {
	for (int i = n / 2; i >= 1; i--) downHeap(i);
}
