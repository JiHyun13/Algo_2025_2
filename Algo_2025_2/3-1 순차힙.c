//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//
////���� ����..
//int H[100];
//int n = 0;
//
//void insertItem(int key);
//int removeMax();
//void upHeap(int i);
//void downHeap(int i);
//void printHeap();
//
//int main() {
//
//	//����
//	char command;
//	int value;
//
//
//	while (1) {
//		scanf("%c", &command);
//		if (command == 'i') {
//			scanf("%d", &value); getchar();
//			insertItem(value);
//		}
//		else if (command == 'd') {
//			printf("%d\n",removeMax());
//		}
//		else if (command == 'p')
//			printHeap();
//		else if (command == 'q')
//			break;
//	}
//}
//
//void insertItem(int key) {
//	if (n > 100) return;
//	H[++n] = key;
//	upHeap(n);
//	printf("0\n");
//}
//int removeMax() {
//	if (n <= 0) return 0;
//	int value = H[1];
//	H[1] = H[n--];
//	if (n > 0) downHeap(1);
//	return value;
//}
//
////�θ�� �˻��ϰ� ��ġ��ȯ(���� �� ���ڸ��� ��ġ����)
//void upHeap(int i) {
//	while (i > 1) {
//		int p = i / 2; //�θ�
//		if (H[p] >= H[i]) break; //������ġ
//		int tmp = H[p];
//		H[p] = H[i];
//		H[i] = tmp;
//		i = p;
//	}
//}
//
////�ڽİ� �˻��ϰ� ��ġ��ȯ(���� ������ ������//)
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