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
//	//1. 크기가 N인 배열 동적할당
//	int N;
//	scanf("%d", &N);
//	int* arr = (int*)malloc(sizeof(int) * N);
//
//	//2. 리스트 값 입력
//	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
//
//	//3. inPlaceQuickSort
//	inPlaceQuickSort(arr,0,N-1);
//
//	for (int i = 0; i < N; i++) printf(" %d", arr[i]);
//}
//
//void inPlaceQuickSort(int* arr, int l, int r) {
//	//정상적으로 입력될 때만 실행
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
//	// pivot을 맨 앞(l)로 옮겨두기 --> 안옮겨두면 그 부분 정렬이 잘안됨
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
//	//원상복귀
//	tmp = arr[l]; arr[l] = arr[high]; arr[high] = tmp;
//
//	return high;
//}
//
//
//
