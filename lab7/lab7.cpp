#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

//добавляем ребро
void addEdge(Node* adjacencyList[], int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    //граф неориентированный, добавляем обратное ребро
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

//новый граф
Node** createG(int size) {
    Node** adjacencyList = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        adjacencyList[i] = NULL;
    }
    return adjacencyList;
}

void printG(Node* adjacencyList[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Вершина %d: ", i);
        Node* temp = adjacencyList[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int* vis = NULL;

void DFS(Node* adjacencyList[], int vertex) {
    vis[vertex] = 1;
    printf("%d ", vertex);
    // Проходим по всем соседям текущей вершины
    Node* temp = adjacencyList[vertex];
    while (temp != NULL) {
        if (!vis[temp->vertex]) {
            DFS(adjacencyList, temp->vertex);
        }
        temp = temp->next;
    }
}

int main(void) {
    setlocale(LC_ALL, "");
    int nG, s;

    printf("Введите размер графа: ");
    scanf("%d", &nG);
    Node** G = createG(nG);
    printf("Введите количество рёбер: ");
    int edges;
    scanf("%d", &edges);
    printf("Введите рёбра (номера двух смежных вершин):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(G, u, v);
    }
    printG(G, nG);
    vis = (int*)malloc(nG * sizeof(int));
    for (int i = 0; i < nG; i++) {
        vis[i] = 0;
    }
    printf("Введите стартовую вершину: ");
    scanf("%d", &s);
    printf("Результат обхода: ");
    DFS(G, s);

    return 0;
}
