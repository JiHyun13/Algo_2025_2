//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h> //시간 측정을 위한 라이브러리
//
//int MAX = 15; //최대값 15 설정 / 30이 느리게 실행됨.
//int A[60];
//int H[60];
//
////DC,DP,출력,알고리즘 사용 시 소요 비용 구하는 함수
//long airtelDC(int n, int s, int d);
//long airtelDP(int n, int s, int d);
//void printCPUTIME(int n, int s, int d, long mincost, char* version, double cputime);
//long getCost(int s, int d);
//
//int main() {
//
//    //시간을 측정하기 위한 변수, 함수 설정
//    LARGE_INTEGER ticksPerSec;
//    LARGE_INTEGER start, end, diff;
//    double t;
//    long result;
//    QueryPerformanceFrequency(&ticksPerSec);
//
//    // 문제 조건에 맞춰 A, H 배열 초기화
//    A[0] = 0;
//    A[1] = 1;
//    for (int i = 2; i < MAX; i++) A[i] = A[i - 1] + (A[i - 1] % 5) + 3;
//
//    H[0] = 0;
//    H[1] = 5;
//    for (int i = 2; i < MAX; i++) H[i] = (H[i - 1] + i) % 9 + 1;
//
//    printf("n   s   d   mincost   version   cputime\n");
//
//    //테스트 
//    int n = 6;
//    int test[3][2] = { {0, 4}, {2, 5}, {2, 4} };
//
//    for (int i = 0; i < 3; i++) {
//        int s = test[i][0]; //위의 배열에서 하나씩 가져옴
//        int d = test[i][1]; 
//
//        //측정 시작 -> 함수 호출 -> 측정 종료 -> 시간 측정 -> 출력 순서
//        QueryPerformanceCounter(&start); //DC 측정 시작
//        result = airtelDC(n, s, d);
//        QueryPerformanceCounter(&end); //DC 측정 종료
//        diff.QuadPart = end.QuadPart - start.QuadPart;
//        t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000.0; // ms 단위 변환
//        printCPUTIME(n, s, d, result, "DC", t);
//
//        QueryPerformanceCounter(&start);
//        result = airtelDP(n, s, d);
//        QueryPerformanceCounter(&end);
//        diff.QuadPart = end.QuadPart - start.QuadPart;
//        t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000.0;
//        printCPUTIME(n, s, d, result, "DP", t);
//    }
//
//    //MAX 값으로 수행
//    n = MAX;
//    int s = 1; //s, d 값 
//    int d = n - 2;
//
//    QueryPerformanceCounter(&start); //DC 측정 시작
//    result = airtelDC(n, s, d);
//    QueryPerformanceCounter(&end); //DC 측정 종료
//    diff.QuadPart = end.QuadPart - start.QuadPart;
//    t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000.0;
//    printCPUTIME(n, s, d, result, "DC", t);
//
//    QueryPerformanceCounter(&start);//DP 측정 시작
//    result = airtelDP(n,s , d);
//    QueryPerformanceCounter(&end);//DP 측정 시작
//    diff.QuadPart = end.QuadPart - start.QuadPart;
//    t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000.0;
//    printCPUTIME(n, s, d, result, "DP", t);
//
//    return 0;
//}
//
//long getCost(int s, int d) {
//    if (s == d) return 0;
//    long diff = A[d] - A[s];
//    return diff * diff; // 이동 비용: 거리 차의 제곱
//}
//
//long airtelDC(int n, int s, int d) {
//    if (s == d) return 0;
//
//    //일단 s,d 넣어서 비용 초기값 설정
//    long min_c = getCost(s, d);
//
//    // 시작점 s와 도착점 d 사이의 모든 경유지 k 탐색
//    for (int k = s + 1; k < d; k++) {
//        // 분할 정복: s->k 비용 + k->d 비용 + 추가비용 H[k]
//        long temp = airtelDC(n, s, k) + airtelDC(n, k, d) + H[k];
//        if (temp < min_c) min_c = temp; //최소값을 찾으면 갱신
//    }
//    return min_c;
//}
//
//long airtelDP(int n, int s, int d) {
//    long m[60][60] = { 0 }; //최소비용 저장 배열, 0으로 초기화
//
//    // gap(구간 길이)을 1부터 늘려가며 상향식(Bottom-up) 계산
//    // ex. gap=1: 바로 옆칸으로 가는 비용 계산, 2: 1로 구한 값들을 이용해 두칸 떨어진 비용...
//    for (int gap = 1; gap <= d - s; gap++) {
//        for (int i = s; i <= d - gap; i++) { 
//            int j = i + gap; //i에서 gap 만큼 떨어진 곳
//            long min_c = getCost(i, j); // 비용 계산
//
//            // i와 j 사이 최적의 분할 지점 k 찾기
//            for (int k = i + 1; k < j; k++) {
//                long temp = m[i][k] + m[k][j] + H[k]; // 메모이제이션 된 값 활용
//                if (temp < min_c) min_c = temp;
//            }
//            m[i][j] = min_c; // 계산된 최솟값 테이블에 저장
//        }
//    }
//    return m[s][d]; //완성된 배열의 (s,d)번째 리턴
//}
//
//void printCPUTIME(int n, int s, int d, long mincost, char* version, double cputime) {
//    printf("%2d %3d %3d   %4ld       %s     %6.8f\n", n, s, d, mincost, version, cputime); //차례대로 출력
//}