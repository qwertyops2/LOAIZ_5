#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "locale.h"

void print(int** matA, int n, int cou) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cou; j++) {
			printf("%d ", matA[i][j]);
		}
		printf("\n");
	}
}

int main() {

	setlocale(LC_ALL, "");

	srand(time(NULL));

	int n;
	int svyaz, cou = 0;
	printf("Введите количество вершин графа: ");
	scanf("%d", &n);

	int** matA = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		matA[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			svyaz = rand() % 2;
			matA[i][j] = svyaz;
			matA[j][i] = svyaz;
		}
	}
	printf("Матрица смежности:\n");
	print(matA, n, n);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (matA[i][j] == 1) {
				cou++;
			}
		}
	}
	printf("\nРазмер графа G: %d\n", cou);

	
	int* Izol = (int*)malloc(n * sizeof(int));
	int* Konc = (int*)malloc(n * sizeof(int));
	int* Domin = (int*)malloc(n * sizeof(int));
	int cI = 0, cK = 0, cD = 0;

	int versh = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			k += matA[i][j];
		}
		if (k == 0) {
			Izol[cI++] = i;
		}
		else if (k == 1) {
			Konc[cK++] = i;
		}
		else if (k == n) {
			Domin[cD++] = i;
		}
		versh++;
		k = 0;
	}

	printf("\nИзолированные вершины: ");
	for (int i = 0; i < cI; i++) {
		printf("%d ", Izol[i] + 1);
	}

	printf("\nКонцевые вершины: ");
	for (int i = 0; i < cK; i++) {
		printf("%d ", Konc[i] + 1);
	}

	printf("\nДоминирующие вершины: ");
	for (int i = 0; i < cD; i++) {
		printf("%d ", Domin[i] + 1);
	}
	printf("\n");

	return 0;
}