//#include<stdio.h>
//#include<stdlib.h>
//
////�迭, Ű, start,end, ans!
//int binarySearch(int* arr, int k, int s, int e, int ans);
//int main() {
//
//    int n, k;
//    scanf("%d %d", &n, &k);
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
//    printf("%d", binarySearch(arr, k, 0, n - 1, -1)); //�⺻������ ans=-1
//
//    free(arr);
//    return 0;
//}
//
//int binarySearch(int* arr, int k, int s, int e, int ans) {
//    if (s > e) return ans; //���̻� Ž���� ���ϸ� ans ��ȯ.
//
//    int mid = (s + e) / 2;
//    if (k == arr[mid]) return mid; //��ġ�ϸ� mid.
//    else if (k > arr[mid]) return binarySearch(arr, k, mid + 1, e, mid); //k�� ũ�� mid+1~e ���� ��Ž��. �� �� k���� ���� �� mid�� ans��
//    else return binarySearch(arr, k, s, mid - 1, ans);
//
//}