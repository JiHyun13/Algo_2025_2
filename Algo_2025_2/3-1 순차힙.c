//#include<stdio.h>
//
////순차힙 -> 의미는 배열로 구현한거. 
//int H[100], n = 0;//1. var 
//
//void insertItem(int key);
//int removeMax();
//void upHeap(int i);
//void downHeap(int i);
//void printHeap();
//
//int main() {
//
//    char c;
//    int key;
//
//    while (1) {
//        scanf("%c", &c);
//        if (c == 'i') { //insert
//            scanf(" %d", &key);
//            insertItem(key);
//            printf("0\n");
//        }
//        else if (c == 'd') printf("%d\n", removeMax());
//        else if (c == 'p') printHeap();
//        else if (c == 'q') break; //quit
//    }
//
//    return 0;
//}
//
//void insertItem(int key) {
//    if (n > 100) return; // max
//    H[++n] = key;
//    upHeap(n);
//}
//int removeMax() {
//    if (n < 1) return 0; //min
//    int key = H[1];
//    H[1] = H[n--];
//    downHeap(1);
//    return key;
//}
//void upHeap(int i) { //n -> 1(root)
//    if (i <= 1) return;
//
//    int p = i / 2;
//    if (H[p] <= H[i]) { //point: upHeap 에서는 그냥 부모 구해서 바로 i랑 비교 ->swap & 재귀 돌리면됨!!
//        int tmp = H[p]; H[p] = H[i]; H[i] = tmp;
//        upHeap(p);
//    }
//}
//void downHeap(int i) { // 1-> leafNode
//    if (i >= n) return;
//    int compare = i, left = i * 2, right = i * 2 + 1;
//
//    if (left <= n && H[compare] <= H[left]) compare = left;
//    if (right <= n && H[compare] <= H[right]) compare = right;
//
//    if (compare != i) { //point: downHeap 에서는 i랑 left랑 right 랑 크기 비교해줘서 가장 큰 값 구하고 바로 i랑 비교 -> swap&재귀 돌리면됨!!
//        int tmp = H[compare]; H[compare] = H[i]; H[i] = tmp;
//        downHeap(compare);
//    }
//}
//void printHeap() {
//    for (int i = 1; i <= n; i++) printf(" %d", H[i]);
//    printf("\n");
//}