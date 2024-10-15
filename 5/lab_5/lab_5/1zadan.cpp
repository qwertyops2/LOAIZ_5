#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "locale.h"

void vershin(int** mat, int n, int cou, int* Izol, int* Konc, int* Domin) {
	int versh = 0;
	int k = 0;
	int cI = 0, cK = 0, cD = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cou; j++) {
			k += mat[i][j];
		}
		if (k == 0) {
			Izol[cI++] = i;
		}
		else if (k == 1) {
			Konc[cK++] = i;
		}
		else if (k == n - 1) {
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
}

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
	int svyaz;
	printf("Введите количество вершин графа: ");
	scanf("%d", &n);

	int verot;
	int verot_p;
	printf("Введите вероятность появления вершины в % (от 0 до 100): ");
	scanf("%d", &verot_p);

	int* Izol = (int*)malloc(n * sizeof(int));
	int* Konc = (int*)malloc(n * sizeof(int));
	int* Domin = (int*)malloc(n * sizeof(int));

	int** matA = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		matA[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			verot = rand() % 101;
			if (verot <= verot_p) {
				matA[i][j] = 1;
				matA[j][i] = 1;
			}
			else {
				matA[i][j] = 0;
				matA[j][i] = 0;
			}

			if (i == j) {
				matA[j][i] = 0;
			}
		}
	}
	print(matA, n, n);

	int cou = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (matA[i][j] == 1) {
				cou++;
			}
		}
	}

	vershin(matA, n, n, Izol, Konc, Domin);

	free(Izol);
	free(Konc);
	free(Domin);

	printf("\nРазмер графа: %d\n", cou);

	if (cou == 0) {
		printf("\nМатрица инцендетности не получится, ребер нет.\nВсе вершины изолированные.\n\n");
		return 0;
	}

	int** matAI = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		matAI[i] = (int*)malloc(cou * sizeof(int));
		for (int j = 0; j < cou; j++) {
			matAI[i][j] = 0;
		}
	}

	int versh = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (matA[i][j] == 1) {
				matAI[i][versh] = 1;
				matAI[j][versh] = 1;
				versh++;
			}
		}
	}
	printf("\nМатрица инцидентности: \n");
	print(matAI, n, cou);

	vershin(matAI, n, cou, Izol, Konc, Domin);

	return 0;
}
//ввести понятие вероятность появления ребра - если ближе к 100% то матр полноценная, если ближе к 0, то меньше вер-ть полноценности