//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//
////���� ����..
//int H[100];
//int n = 0;
//
//void downHeap(int i);
//void printHeap();
//void rBuildHeap(int i);
//void buildHeap();
//
//int main() {
//
//	//����
//	int count,key;
//
//	scanf("%d", &count);
//	n = count;
//
//	for (int i = 1; i <= count; i++) scanf("%d", &H[i]);
//
//	buildHeap();
//	printHeap();
//}
//
//void downHeap(int i) {
//	while (1) {
//		int left = i * 2;
//		int right = left + 1;
//		int t = i;
//		if (left <= n && H[left] > H[t]) t = left;
//		if (right <= n && H[right] > H[t]) t = right;
//
//		if (t == i)break;
//
//		int tmp = H[t];
//		H[t] = H[i];
//		H[i] = tmp;
//		i = t;
//	}
//}
//
//void printHeap() {
//	for (int i = 1; i <= n; ++i) {
//		printf(" %d", H[i]);
//	}
//	printf("\n");
//}
//
//void rBuildHeap(int i) {
//	if (i > n) return; //��� ����a
//	rBuildHeap(i * 2); //���ʺ��� down
//	rBuildHeap(i * 2 + 1); //������ down heap
//	downHeap(i);
//
//}
//
//void buildHeap() {
//	for (int i = n / 2; i >= 1; i--) { //���� ���� ��Ʈ�� �ö󰡸鼭 downheap
//		downHeap(i);
//	}
//}