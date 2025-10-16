//#include<stdio.h>
//
//int H[100], n;
//
//void reBuildHeap(int i);
//void buildHeap();
//void downHeap(int i);
//void printHeap();
//
//int main() {
//
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) scanf(" %d", &H[i]);
//    reBuildHeap(1);
//    //buildHeap();
//    printHeap();
//
//    return 0;
//}
//
//void reBuildHeap(int i) { //�� 1���� ���� rebuild, ������ rebuild �������� down �ѹ�~!
//    if (i > n) return; 
//
//    reBuildHeap(i * 2);
//    reBuildHeap(i * 2 + 1);
//
//    downHeap(i);
//
//}
//void buildHeap() { //���� ���� n/2���� 1���� 1���ٸ鼭 down~
//    for (int i = n / 2; i >= 1; i--) downHeap(i);
//}
//
//void downHeap(int i) { //1->n
//    if (i >= n) return;
//
//    int compare = i, left = i * 2, right = i * 2 + 1;
//    if (left <= n && H[compare] <= H[left]) compare = left;
//    if (right <= n && H[compare] <= H[right]) compare = right;
//
//    if (compare != i) {
//        int tmp = H[compare]; H[compare] = H[i]; H[i] = tmp;
//        downHeap(compare);
//    }
//}
//void printHeap() {
//    for (int i = 1; i <= n; i++) printf(" %d", H[i]);
//    printf("\n");
//}