//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<Windows.h>
//
//LARGE_INTEGER ticksPerSec;
//LARGE_INTEGER start, end, diff;
//
//void printArray(int *L, int n);
//int findKthSmallest(int* L, int n, int k);
//int* buildList(int n, int min, int max);
//void downMinHeap(int* L, int n, int i);
//void buildMinHeap(int* L, int n);
//int removeMin(int* L, int n);
//
//
//int main() {
//	//���� �ʱ�ȭ
//	srand((unsigned)time(NULL));
//
//	int k, N, output[3], kArr[] = {1,100,99900,99999}; //N: ���� ����. 
//	double t; //�ҿ�ð�. time. time() �Լ� ȥ�� ����
//
//	//����Ʈ �迭 �� ũ�� ����
//	int *L = buildList(10, 1, 100);
//	printArray(L,10);
//
//	//1. ũ�� 10¥�� �迭���� K�� 3ȸ Ž�� �� ���. 
//	for (k = 0; k < 3; k++) output[k] = findKthSmallest(L, 10, k + 1);
//	for (k = 0; k < 3; k++) printf("(K = %d)����: %d | ", k+1, output[k]);
//	printf("\n");
//
//	free(L);//���Ҵ� �� ����..
//	L = buildList(100000, 1, 1000000);
//
//	QueryPerformanceFrequency(&ticksPerSec);
//
//	//2. ũ�� 100000¥�� �迭���� K�� 4ȸ Ž�� ��, ���� �ð��� �Բ� ���
//	for (k = 0; k < 4; k++) {
//		QueryPerformanceCounter(&start);
//		N = findKthSmallest(L, 100000, kArr[k]); //K�� Ž��
//		QueryPerformanceCounter(&end);
//		diff.QuadPart = end.QuadPart - start.QuadPart;
//		t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
//		printf("(K = %d)����: %d �ҿ�ð�: %.12lf sec\n", kArr[k],N, t);
//	}
//
//	free(L); 
//}
//
//void printArray(int *L, int n) {
//	for (int i = 1; i <= n; i++) printf(" %d", L[i]);
//	printf("\n");
//}
//
//// 
//int findKthSmallest(int* L, int n, int k) {
//	int result=0; //��ȯ��
//
//	//(1) �� ���� -> removeMin ó�� �� 1 �پ��� ������ ���� ����. *O(N)
//	int *H = (int*)malloc(sizeof(int) * (n + 1));
//	for (int i = 1; i <= n; i++) H[i] = L[i];
//
//	buildMinHeap(H, n); //(2) �ּ������� ���� *O(N)
//
//	//(3) K�� ��Ʈ ���� �� result�� ����. * O(klogN)
//	int size = n;
//	for (int t = 1; t <= k; t++) {
//		result = removeMin(H, size--);
//	}
//	free(H);
//	return result; //K��° ���� ��
//	// ==> N+N+klogN ���� ��� ���� ==> O(N+klogN) 
//}
//
//int removeMin(int*L, int n) {
//	if (n <= 0) return 0;
//	//��Ʈ���� value�� ���� �� downHeap���� ������
//	int value = L[1];
//	L[1] = L[n--];
//	if (n > 0) downMinHeap(L,n,1);
//	return value;
//}
//
//int* buildList(int n, int min, int max) {
//	int* L = (int*)malloc(sizeof(int) * (n + 1)); // nũ�� �Ҵ�
//
//	for (int i = 1; i <= n; i++) L[i] = rand() % (max - min + 1) + min; //������ �Ҵ�
//
//	return L; 
//}
//
////�ּ������� downHeap
//void downMinHeap(int*L, int n, int i) {
//	while (1) {
//		int left = i * 2;
//		int right = left + 1;
//		int t = i;
//		if (left <= n && L[left] < L[t]) t = left; //�ε�ȣ ������ �ּ������� ����
//		if (right <= n && L[right] < L[t]) t = right; 
//
//		if (t == i)break;
//
//		int tmp = L[t];L[t] = L[i];L[i] = tmp;
//		i = t;
//	}
//
//}
//void buildMinHeap(int* L, int n) {
//	for (int i = n / 2; i >= 1; i--) { //����ͽ� ������� �ּ���
//		downMinHeap(L, n, i);
//	}
//}