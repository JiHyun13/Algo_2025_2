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
//	//�ڿ������� ������
//	for (i = n - 1; i >= 1; i--) {
//		idx = 0;
//		for (j = 1; j <= i; j++) { //�տ��� i������ Ž��(i���Ĵ� ����)
//			if (arr[idx] < arr[j]) {
//				idx = j; //���� ū ���� ���� ���� �ε��� ������Ʈ
//			}
//		}
//		//swop
//		tmp = arr[idx];
//		arr[idx] = arr[i];
//		arr[i] = tmp;
//	}
//	for (i = 0; i < n; i++) printf(" %d", arr[i]);
//}