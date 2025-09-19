#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

void downHeap(int i);
void printHeap();
void rBuildHeap(int i);
void buildHeap();

int main() {

	//¼±¾ð
	int count,key;

	scanf("%d", &count);
	n = count;

	for (int i = 1; i <= count; i++) scanf("%d", &H[i]);

	buildHeap();
	printHeap();
}

