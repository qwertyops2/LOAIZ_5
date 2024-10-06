#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "locale.h"

void setColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((bgColor << 4) | textColor));
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

	print(matA, n, n);

	int cou = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (matA[i][j] == 1) {
				cou++;
			}
		}
	}

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
	setColor(3, 0);
	printf("\nМатрица инцидентности: \n");
	print(matAI, n, cou);
	setColor(7, 0);

	printf("\nРазмер графа определяется количеством столбов в матрице инцинтентности. \nРазмер графа: %d\n", cou);

	versh = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cou; j++) {
			k += matAI[i][j];
		}
		if (k == 0) {
			printf("\nИзолированная вершина: %d\n", versh + 1);
		}
		else if (k == 1) {
			printf("\nКонцевая вершина: %d\n", versh + 1);
		}
		else if (k == n) {
			printf("\nДоминирующая вершина: %d\n", versh + 1);
		}
		versh++;
		k = 0;
	}
	return 0;
}