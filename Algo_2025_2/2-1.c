//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//
//void seletedSort(int n, int* arr);
//
//int main() {
//	int n,tmp,max,idx,i,j;
//	int *arr;
//
//	scanf("%d ", &n);
//	arr = (int*)malloc(sizeof(int) * n);
//	for (i = 0; i < n; i++) scanf("%d " , &arr[i]);
//
//	seletedSort(n, arr);
//
//}
//
//void seletedSort(int n, int* arr) {
//	int i, j, idx,tmp;
//
//	//뒤에서부터 앞으로
//	for (i = n - 1; i >= 1; i--) {
//		idx = 0;
//		for (j = 1; j <= i; j++) { //앞에서 i까지만 탐색(i이후는 정렬)
//			if (arr[idx] < arr[j]) {
//				idx = j; //가장 큰 값을 가진 원소 인덱스 업데이트
//			}
//		}
//		//swop
//		tmp = arr[idx];
//		arr[idx] = arr[i];
//		arr[i] = tmp;
//	}
//	for (i = 0; i < n; i++) printf(" %d", arr[i]);
//}