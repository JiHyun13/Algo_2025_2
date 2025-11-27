//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//    int vertexIndex;
//    struct Node* next;
//} Node;
//
//typedef struct {
//    char name;
//    Node* outEdges;
//    int inDegree;
//} Vertex;
//
//Vertex* graph;
//int n, m;
//int* topOrder;
//int* queue;
//int front = 0, rear = 0;
//
//void enqueue(int v);
//int dequeue();
//int isEmpty();
//int getIndex(char name);
//void addEdge(int u, int w);
//void buildGraph();
//void topologicalSort();
//
//int main() {
//    buildGraph();
//    topologicalSort();
//
//    for (int i = 0; i < n; i++) {
//        Node* cur = graph[i].outEdges;
//        while (cur != NULL) {
//            Node* temp = cur;
//            cur = cur->next;
//            free(temp);
//        }
//    }
//    free(graph);
//
//    return 0;
//}
//
//void enqueue(int v) {
//    queue[rear++] = v;
//}
//
//int dequeue() {
//    return queue[front++];
//}
//
//int isEmpty() {
//    return front == rear;
//}
//
//int getIndex(char name) {
//    for (int i = 0; i < n; i++) {
//        if (graph[i].name == name) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//void addEdge(int u, int w) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->vertexIndex = w;
//    newNode->next = graph[u].outEdges;
//    graph[u].outEdges = newNode;
//    graph[w].inDegree++;
//}
//
//void buildGraph() {
//    scanf("%d", &n);
//    graph = (Vertex*)malloc(sizeof(Vertex) * n);
//    
//    for (int i = 0; i < n; i++) {
//        scanf(" %c", &graph[i].name);
//        graph[i].outEdges = NULL;
//        graph[i].inDegree = 0;
//    }
//
//    scanf("%d", &m);
//    char uName, wName;
//    for (int i = 0; i < m; i++) {
//        scanf(" %c %c", &uName, &wName);
//        int u = getIndex(uName);
//        int w = getIndex(wName);
//        addEdge(u, w);
//    }
//}
//
//void topologicalSort() {
//    queue = (int*)malloc(sizeof(int) * n);
//    topOrder = (int*)malloc(sizeof(int) * n);
//    int* in = (int*)malloc(sizeof(int) * n);
//
//    for (int i = 0; i < n; i++) {
//        in[i] = graph[i].inDegree;
//        if (in[i] == 0) {
//            enqueue(i);
//        }
//    }
//
//    int t = 0;
//    while (!isEmpty()) {
//        int u = dequeue();
//        topOrder[t++] = u;
//
//        Node* cur = graph[u].outEdges;
//        while (cur != NULL) {
//            int w = cur->vertexIndex;
//            in[w]--;
//            if (in[w] == 0) {
//                enqueue(w);
//            }
//            cur = cur->next;
//        }
//    }
//
//    if (t < n) {
//        printf("0\n");
//    } else {
//        for (int i = 0; i < n; i++) {
//            printf("%c", graph[topOrder[i]].name);
//            if (i < n - 1) printf(" ");
//        }
//        printf("\n");
//    }
//
//    free(queue);
//    free(topOrder);
//    free(in);
//}
//
