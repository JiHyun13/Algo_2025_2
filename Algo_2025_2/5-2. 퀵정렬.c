//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void inPlaceQuickSort(int* arr, int l, int r);
//int findPivot(int l, int r);
//int inPlacePartition(int* arr, int l, int r);
//
//int main() {
//
//	srand((unsigned)time(NULL));
//
//	//1. ũ�Ⱑ N�� �迭 �����Ҵ�
//	int N;
//	scanf("%d", &N);
//	int* arr = (int*)malloc(sizeof(int) * N);
//
//	//2. ����Ʈ �� �Է�
//	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
//
//	//3. inPlaceQuickSort
//	inPlaceQuickSort(arr,0,N-1);
//
//	for (int i = 0; i < N; i++) printf(" %d", arr[i]);
//}
//
//void inPlaceQuickSort(int* arr, int l, int r) {
//	//���������� �Էµ� ���� ����
//	if (l < r) {
//
//		int pivot = inPlacePartition(arr, l, r); 
//
//		inPlaceQuickSort(arr, l, pivot - 1);
//		inPlaceQuickSort(arr, pivot + 1, r);
//	}
//}
//
//int findPivot(int l, int r) {
//	return rand() % (r - l + 1) + l;
//}
//
//int inPlacePartition(int* arr, int l, int r) {
//	int p = findPivot(l, r);
//	int pivot = arr[p];
//	
//	// pivot�� �� ��(l)�� �Űܵα� --> �ȿŰܵθ� �� �κ� ������ �߾ȵ�
//	int tmp = arr[l]; arr[l] = arr[p]; arr[p] = tmp;
//
//	int low = l + 1;
//	int high = r;
//
//	while(low <= high) {
//		while (low <= r && arr[low] <= pivot) low++;
//		while (high >= l + 1 && arr[high] > pivot) high--;
//
//		if (low < high) {
//			tmp = arr[low]; arr[low] = arr[high]; arr[high] = tmp;
//		}
//	}
//	//���󺹱�
//	tmp = arr[l]; arr[l] = arr[high]; arr[high] = tmp;
//
//	return high;
//}
//
//
//
