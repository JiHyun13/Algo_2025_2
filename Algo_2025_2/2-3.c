//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<Windows.h>
//
//void insertSort(int n, int* arr);
//void seletedSort(int n, int* arr);
//void initArr(int n, int* arr);
//double getSpeed(void (*func)(int, int*), int n, int* arr);
//
//int main() {
//	int n;
//	int* A, *B;
//
//	scanf("%d", &n);
//	A = (int*)malloc(sizeof(int) * n);
//	B = (int*)malloc(sizeof(int) * n);
//	initArr(n, A);
//	initArr(n, B);
//
//	//1. 랜덤값으로 초기화 후 시간 측정
//	printf("1. 랜덤값으로 초기화 후 시간 측정\n");
//	double timeA = 0, timeB = 0;
//	for (int i = 0; i < 100; i++) {
//		timeA+=getSpeed(seletedSort, n, A);
//		timeB+=getSpeed(insertSort, n, B);
//	}
//	printf("평균 선택 정렬 소요 시간(100회): %.9lf ms\n", timeA / 100);
//	printf("평균 삽입 정렬 소요 시간(100회): %.9lf ms\n", timeB / 100);
//	printf("===========================================\n");
//	
//	//2. 이미 정렬된 배열에 대해 시간 측정
//	printf("2. 이미 정렬된 배열에 대해 시간 측정\n");
//	timeA = 0, timeB = 0;
//	for (int i = 0; i < 100; i++) {
//		seletedSort(n,A); seletedSort(n,B);
//		timeA += getSpeed(seletedSort, n, A);
//		timeB += getSpeed(insertSort, n, B);
//	}
//	printf("평균 선택 정렬 소요 시간(100회): %.9lf ms\n", timeA / 100);
//	printf("평균 삽입 정렬 소요 시간(100회): %.9lf ms\n", timeB / 100);
//	printf("===========================================\n");
//	
//	//3. 역순으로 정렬된 배열에 대해 시간 측정
//	printf("3. 역순으로 정렬된 배열에 대해 시간 측정\n");
//	timeA = 0, timeB = 0;
//	for (int i = 0; i < 100; i++) {
//		seletedSort(-1*n, A);
//		seletedSort(-1 * n, B);
//		timeA += getSpeed(seletedSort, n, A);
//		timeB += getSpeed(insertSort, n, B);
//	}
//	printf("평균 선택 정렬 소요 시간(100회): %.9lf ms\n", timeA / 100);
//	printf("평균 삽입 정렬 소요 시간(100회): %.9lf ms\n", timeB / 100);
//	printf("===========================================\n");
//
//	return 0;
//}
//
//void insertSort(int n, int* arr) {
//	int i, j, num;
//
//	for (i = 1; i <n; i++) {
//		num = arr[i];
//		for (j = i-1; arr[j]>num && j>=0; j--) {
//			arr[j + 1] = arr[j];
//		}
//		arr[j + 1] = num;
//	}
//}
//
//void seletedSort(int n, int* arr) {
//	int i, j, idx,tmp;
//
//	if (n < 0) {
//		n *= -1;
//		for (i = n - 1; i >= 1; i--) {
//			idx = 0;
//			for (j = 1; j <= i; j++) {
//				if (arr[idx] < arr[j]) {
//					idx = j;
//				}
//			}
//			tmp = arr[idx];
//			arr[idx] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//	else {
//
//		for (i = n - 1; i >= 1; i--) {
//			idx = 0;
//			for (j = 1; j <= i; j++) {
//				if (arr[idx] < arr[j]) {
//					idx = j;
//				}
//			}
//			tmp = arr[idx];
//			arr[idx] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//}
//
//void initArr(int n, int* arr) {
//	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
//}
//
//double getSpeed(void (*func)(int, int*), int n, int* arr) {
//	LARGE_INTEGER ticksPerSec;
//	LARGE_INTEGER start, end, diff;
//	QueryPerformanceFrequency(&ticksPerSec);
//	QueryPerformanceCounter(&start);
//
//	func(n, arr);
//	
//	QueryPerformanceCounter(&end);
//	diff.QuadPart = end.QuadPart - start.QuadPart;
//	return  ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000;
//}
