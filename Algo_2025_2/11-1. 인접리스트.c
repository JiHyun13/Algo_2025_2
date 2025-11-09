//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Incidence {
//	int edgeIdx;
//	struct Incidence* next;
//} Incidence;
//
//typedef struct Vertex {
//	int num;
//	Incidence* head;
//} Vertex;
//
//typedef struct Edge {
//	int u, v, w;
//} Edge;
//
//typedef struct Graph {
//	Vertex v[7];
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
//void freeGraph();
//
//static inline int other(int idx, int u) {
//	return (G->e[idx].u == u) ? G->e[idx].v : G->e[idx].u;
//}
//
//static Incidence* newInc(int idx) {
//	Incidence* p = malloc(sizeof(Incidence));
//	p->edgeIdx = idx; p->next = NULL;
//	return p;
//}
//
//void insertInc(int u, int v, Incidence* node) {
//	Incidence** p = &G->v[u].head;
//	while (*p && other((*p)->edgeIdx, u) < v) p = &(*p)->next;
//	node->next = *p; *p = node;
//}
//
//void delInc(int u, int v) {
//	Incidence** p = &G->v[u].head;
//	while (*p) {
//		if (other((*p)->edgeIdx, u) == v) {
//			Incidence* t = *p; *p = t->next; free(t); return;
//		}
//		p = &(*p)->next;
//	}
//}
//
//int main() {
//	initGraph();
//	char cmd; int a, b, w;
//	while (scanf(" %c", &cmd) == 1) {
//		if (cmd == 'q') break;
//		else if (cmd == 'a') { scanf("%d", &a); printEdge(a); }
//		else if (cmd == 'm') { scanf("%d%d%d", &a, &b, &w); modifyEdge(a, b, w); }
//	}
//	freeGraph();
//}
//
//void initGraph() {
//	G = malloc(sizeof(Graph));
//	G->edgeSize = 0;
//	for (int i = 1; i <= 6; i++) { G->v[i].num = i; G->v[i].head = NULL; }
//
//	insertEdge(1, 2, 1);
//	insertEdge(1, 3, 1);
//	insertEdge(1, 4, 1);
//	insertEdge(1, 6, 2);
//	insertEdge(2, 3, 1);
//	insertEdge(3, 5, 4);
//	insertEdge(5, 5, 4);
//	insertEdge(5, 6, 3);
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
//	insertInc(u, v, newInc(idx));
//	if (u != v) insertInc(v, u, newInc(idx));
//}
//
//void modifyEdge(int u, int v, int w) {
//	if (u < 1 || u>6 || v < 1 || v>6) { printf("-1\n"); return; }
//	if (w == 0) { deleteEdge(u, v); return; }
//
//	for (int i = 0; i < G->edgeSize; i++) {
//		if ((G->e[i].u == u && G->e[i].v == v) || (G->e[i].u == v && G->e[i].v == u)) {
//			G->e[i].w = w; return;
//		}
//	}
//	insertEdge(u, v, w);
//}
//
//void deleteEdge(int u, int v) {
//	if (u < 1 || u>6 || v < 1 || v>6) { printf("-1\n"); return; }
//	delInc(u, v); if (u != v) delInc(v, u);
//}
//
//void printEdge(int u) {
//	if (u < 1 || u>6) { printf("-1\n"); return; }
//	Incidence* p = G->v[u].head;
//	if (!p) { printf("-1\n"); return; }
//	while (p) { printf(" %d %d", other(p->edgeIdx, u), G->e[p->edgeIdx].w); p = p->next; }
//	printf("\n");
//}
//
//void freeGraph() {
//	for (int i = 1; i <= 6; i++) {
//		Incidence* p = G->v[i].head;
//		while (p) { Incidence* t = p; p = p->next; free(t); }
//	}
//	free(G);
//}
