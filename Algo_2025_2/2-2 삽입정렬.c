//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//
//void insertSort(int n, int* arr);
//
//int main() {
//	int n;
//	int* arr;
//
//	scanf("%d ", &n);
//	arr = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++) scanf("%d ", &arr[i]);
//
//	insertSort(n, arr);
//
//}
//
//
//void insertSort(int n, int* arr) {
//	int i, j, num;
//
//	for (i = 1; i <n; i++) { //0 빼고 1부터 탐색. 
//		num = arr[i];
//		for (j = i-1; arr[j]>num && j>=0; j--) { //뒤에서부터 앞까지 탐색, num 보다 크다면 << 조건추가해서 shift
//			arr[j + 1] = arr[j]; //큰 수면 뒤로 밀고, num보다 작아지는순간 stop
//		}
//		arr[j + 1] = num; //해당자리에 num 삽입
//	}
//	for (i = 0; i < n; i++) printf(" %d", arr[i]);
//}