//#include<stdio.h>
//
//int H[100], n = 0;
//
//void buildHeap();
//void downHeap(int i);
//void inPlaceHeapSort();
//void printArray();
//
//int main() {
//
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) scanf(" %d", &H[i]);
//    inPlaceHeapSort();
//    printArray();
//    return 0;
//}
//void buildHeap() {
//    for (int i = n / 2; i >= 1; i--) downHeap(i);
//}
//void downHeap(int i) {
//    if (i > n) return;
//    int t = i, l = t * 2, r = t * 2 + 1;
//    if (l <= n && H[t] < H[l]) t = l;
//    if (r <= n && H[t] < H[r]) t = r;
//    if (t != i) {
//        int tmp = H[t]; H[t] = H[i]; H[i] = tmp;
//        downHeap(t);
//    }
//}
//
//void inPlaceHeapSort() {
//    buildHeap(); //1. �ִ��� �����. �ִ���->����, �ּ���->����
//    int m = n; //������
//    for (int i = n; i > 1; i--) { //1�� ���ĉ����ϱ� n~2���� ��Ʈ �ѹ��� �����ֱ�
//        int tmp = H[i]; H[i] = H[1]; H[1] = tmp;
//        n--; //1���̰� �ٿ����ؾߵ�.
//        downHeap(1);
//    }
//    n = m;
//}
//void printArray() {
//    for (int i = 1; i <= n; i++) printf(" %d", H[i]);
//}