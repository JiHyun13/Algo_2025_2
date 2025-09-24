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
//	//난수 초기화
//	srand((unsigned)time(NULL));
//
//	int k, N, output[3], kArr[] = {1,100,99900,99999}; //N: 원소 저장. 
//	double t; //소요시간. time. time() 함수 혼용 방지
//
//	//리스트 배열 및 크기 선언
//	int *L = buildList(10, 1, 100);
//	printArray(L,10);
//
//	//1. 크기 10짜리 배열에서 K값 3회 탐색 후 출력. 
//	for (k = 0; k < 3; k++) output[k] = findKthSmallest(L, 10, k + 1);
//	for (k = 0; k < 3; k++) printf("(K = %d)원소: %d | ", k+1, output[k]);
//	printf("\n");
//
//	free(L);//재할당 전 해제..
//	L = buildList(100000, 1, 1000000);
//
//	QueryPerformanceFrequency(&ticksPerSec);
//
//	//2. 크기 100000짜리 배열에서 K값 4회 탐색 후, 실행 시간과 함께 출력
//	for (k = 0; k < 4; k++) {
//		QueryPerformanceCounter(&start);
//		N = findKthSmallest(L, 100000, kArr[k]); //K값 탐색
//		QueryPerformanceCounter(&end);
//		diff.QuadPart = end.QuadPart - start.QuadPart;
//		t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
//		printf("(K = %d)원소: %d 소요시간: %.12lf sec\n", kArr[k],N, t);
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
//	int result=0; //반환용
//
//	//(1) 값 복사 -> removeMin 처리 후 1 줄어들기 때문에 원본 유지. *O(N)
//	int *H = (int*)malloc(sizeof(int) * (n + 1));
//	for (int i = 1; i <= n; i++) H[i] = L[i];
//
//	buildMinHeap(H, n); //(2) 최소힙으로 변경 *O(N)
//
//	//(3) K번 루트 삭제 및 result에 저장. * O(klogN)
//	int size = n;
//	for (int t = 1; t <= k; t++) {
//		result = removeMin(H, size--);
//	}
//	free(H);
//	return result; //K번째 작은 값
//	// ==> N+N+klogN 에서 상수 없앰 ==> O(N+klogN) 
//}
//
//int removeMin(int*L, int n) {
//	if (n <= 0) return 0;
//	//루트값을 value로 지정 후 downHeap으로 재정렬
//	int value = L[1];
//	L[1] = L[n--];
//	if (n > 0) downMinHeap(L,n,1);
//	return value;
//}
//
//int* buildList(int n, int min, int max) {
//	int* L = (int*)malloc(sizeof(int) * (n + 1)); // n크기 할당
//
//	for (int i = 1; i <= n; i++) L[i] = rand() % (max - min + 1) + min; //랜덤값 할당
//
//	return L; 
//}
//
////최소힙으로 downHeap
//void downMinHeap(int*L, int n, int i) {
//	while (1) {
//		int left = i * 2;
//		int right = left + 1;
//		int t = i;
//		if (left <= n && L[left] < L[t]) t = left; //부등호 방향을 최소힙으로 설정
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
//	for (int i = n / 2; i >= 1; i--) { //비재귀식 방법으로 최소힙
//		downMinHeap(L, n, i);
//	}
//}