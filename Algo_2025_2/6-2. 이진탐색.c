//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//int binarySearch(int start, int end, int k, int* arr, int ans);
//
//int main() {
//    int n, k, idx;
//    scanf("%d %d", &n, &k);
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
//
//    idx = binarySearch(0, n - 1, k, arr, n); 
//
//    printf("%d", idx);
//    free(arr);
//    return 0;
//}
//
//int binarySearch(int start, int end, int k, int* arr, int ans) {
//
//    while (start <= end) {
//        int mid = (start + end) / 2;
//
//        if (arr[mid] < k) {
//            start = mid + 1;
//        }
//        else {
//            ans = mid;
//            end = mid - 1;
//        }
//
//    }
//    return ans;
//}
