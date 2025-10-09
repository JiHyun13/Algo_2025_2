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
//    idx = binarySearch(0, n - 1, k, arr, -1); 
//
//    printf("%d", idx);
//    free(arr);
//    return 0;
//}
//
//int binarySearch(int start, int end, int k, int* arr, int ans) {
//    if (start > end) return ans;
//
//    int mid = (start + end) / 2;
//
//    if (arr[mid] == k) return mid; // 정확히 같으면 바로 반환
//    else if (arr[mid] < k) {
//        ans = mid; 
//        return binarySearch(mid + 1, end, k, arr, ans);
//    }
//    else {
//        return binarySearch(start, mid - 1, k, arr, ans);
//    }
//}
