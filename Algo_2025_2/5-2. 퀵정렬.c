//#include<stdio.h>
//#include<stdlib.h>
//
//void sort(int* arr, int l, int r);
//int partition(int* arr, int l, int r);
//void swap(int* a, int* b);
//
//int main() {
//
//    int n;
//    scanf("%d", &n);
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
//    sort(arr, 0, n - 1);
//    for (int i = 0; i < n; i++) printf(" %d", arr[i]);
//    return 0;
//}
//
//void sort(int* arr, int l, int r) {
//    if (l >= r) return;
//    int p = partition(arr, l, r);
//    sort(arr, l, p - 1);
//    sort(arr, p + 1, r);
//}
//int partition(int* arr, int l, int r) {
//    int p = rand() % (r - l + 1) + l;
//    swap(&arr[p], &arr[r]);
//
//    int i = l;
//    for (int j = l; j < r; j++) {
//        if (arr[j] <= arr[r]) swap(&arr[i++], &arr[j]);
//    }
//    swap(&arr[i], &arr[r]);
//    return i;
//}
//void swap(int* a, int* b) {
//    int tmp = *a; *a = *b; *b = tmp;
//}