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
//	for (i = 1; i <n; i++) { //0 ���� 1���� Ž��. 
//		num = arr[i];
//		for (j = i-1; arr[j]>num && j>=0; j--) { //�ڿ������� �ձ��� Ž��, num ���� ũ�ٸ� << �����߰��ؼ� shift
//			arr[j + 1] = arr[j]; //ū ���� �ڷ� �а�, num���� �۾����¼��� stop
//		}
//		arr[j + 1] = num; //�ش��ڸ��� num ����
//	}
//	for (i = 0; i < n; i++) printf(" %d", arr[i]);
//}