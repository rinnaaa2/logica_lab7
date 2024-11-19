#include <iostream>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

int** createG(int size) {
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		G[i] = (int*)malloc(size * sizeof(int));
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}
	}
	return G;
}

void printG(int** G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
}
int* vis = NULL;
void DFS(int** G, int nG, int s) {
	int* vis = (int*)malloc(nG * sizeof(int));
	for (int i = 0; i < nG; i++) {
		vis[i] = 0;
	}

	int* st = (int*)malloc(nG * sizeof(int));  //типо стек
	int vershina = 0;  // типо вершина стека
	st[vershina] = s;  //стартовую вершину в стек
	vis[s] = 1; 

	while (vershina >= 0) {  // Пока стек не пуст
		int node = st[vershina--];  //следующая вершина
		printf("%d ", node); 

		//проход по соседним вершинам
		for (int i = 0; i < nG; i++) {
			if (G[node][i] == 1 && vis[i] == 0) {  // Если вершины i и node смежные, и i не была посещена
				vis[i] = 1; 
				st[++vershina] = i;  //закинули в стек и пошли дальше
			}
		}
	}
}

void main(void)
{
	setlocale(LC_ALL, "");
	int** G = NULL;
	int nG, s;
	printf("Введите размер графа:");
	scanf("%d", &nG);
	G = createG(nG);
	printG(G, nG);
	printf("Введите стартовую вершину:");
	scanf("%d", &s);
	vis = (int*)malloc(nG * sizeof(int));
	for (int i = 0; i < nG; i++) {
		vis[i] = 0;
	}
	DFS(G, nG, s);
}