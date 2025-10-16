//#include<stdio.h>
//#include<stdlib.h>
//
////배열, 키, start,end, ans!
//int binarySearch(int* arr, int k, int s, int e, int ans);
//int main() {
//
//    int n, k;
//    scanf("%d %d", &n, &k);
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
//    printf("%d", binarySearch(arr, k, 0, n - 1, -1)); //기본적으로 ans=-1
//
//    free(arr);
//    return 0;
//}
//
//int binarySearch(int* arr, int k, int s, int e, int ans) {
//    if (s > e) return ans; //더이상 탐색을 못하면 ans 반환.
//
//    int mid = (s + e) / 2;
//    if (k == arr[mid]) return mid; //일치하면 mid.
//    else if (k > arr[mid]) return binarySearch(arr, k, mid + 1, e, mid); //k가 크면 mid+1~e 에서 재탐색. 이 때 k보다 작은 값 mid를 ans로
//    else return binarySearch(arr, k, s, mid - 1, ans);
//
//}