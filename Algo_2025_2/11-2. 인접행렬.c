//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct { int u, v, w; } Edge;
//typedef struct {
//	int adj[6][6];
//	Edge e[21];
//	int edgeSize;
//} Graph;
//
//Graph* G;
//
//void initGraph();
//void insertEdge(int u, int v, int w);
//void modifyEdge(int u, int v, int w);
//void deleteEdge(int u, int v);
//void printEdge(int u);
//
//int main() {
//	char c; int a, b, w;
//	initGraph();
//	while (scanf(" %c", &c) == 1) {
//		if (c == 'q') break;
//		else if (c == 'a') { scanf("%d", &a); printEdge(a - 1); }
//		else if (c == 'm') {
//			scanf("%d%d%d", &a, &b, &w);
//			if (w) modifyEdge(a - 1, b - 1, w);
//			else deleteEdge(a - 1, b - 1);
//		}
//	}
//	free(G);
//}
//
//void initGraph() {
//	G = malloc(sizeof(Graph));
//	G->edgeSize = 0;
//	for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) G->adj[i][j] = -1;
//	insertEdge(0, 1, 1); insertEdge(0, 2, 1); insertEdge(0, 3, 1);
//	insertEdge(0, 5, 2); insertEdge(1, 2, 1); insertEdge(2, 4, 4);
//	insertEdge(4, 4, 4); insertEdge(4, 5, 3);
//}
//
//void insertEdge(int u, int v, int w) {
//	for (int i = 0; i < G->edgeSize; i++) {
//		if ((G->e[i].u == u && G->e[i].v == v) || (G->e[i].u == v && G->e[i].v == u)) {
//			G->e[i].w = w; return;
//		}
//	}
//	int idx = G->edgeSize++;
//	G->e[idx] = (Edge){ u,v,w };
//	G->adj[u][v] = G->adj[v][u] = idx;
//}
//
//void modifyEdge(int u, int v, int w) {
//	if (u < 0 || u>5 || v < 0 || v>5) { printf("-1\n"); return; }
//	if (G->adj[u][v] == -1) insertEdge(u, v, w);
//	else G->e[G->adj[u][v]].w = w;
//}
//
//void deleteEdge(int u, int v) {
//	if (u < 0 || u>5 || v < 0 || v>5) { printf("-1\n"); return; }
//	if (G->adj[u][v] == -1) return;
//	G->adj[u][v] = G->adj[v][u] = -1;
//	G->edgeSize--;
//}
//
//void printEdge(int u) {
//	if (u < 0 || u>5) { printf("-1\n"); return; }
//	int found = 0;
//	for (int i = 0; i < 6; i++) {
//		int idx = G->adj[u][i];
//		if (idx != -1) { printf(" %d %d", i + 1, G->e[idx].w); found = 1; }
//	}
//	if (!found) printf("-1");
//	printf("\n");
//}
