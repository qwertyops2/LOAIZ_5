//#define _CRT_SECURE_NO_WARNINGS
//
//#include "stdlib.h"
//#include "stdio.h"
//#include "time.h"
//#include "locale.h"
//
//void print(int** matA, int n, int cou) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < cou; j++) {
//			printf("%d ", matA[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//
//	setlocale(LC_ALL, "");
//
//	srand(time(NULL));
//
//	int n;
//	int svyaz, cou = 0;
//	printf("Введите размер матрицы: ");
//	scanf("%d", &n);
//
//	//задание 1
//	int** matA = (int**)malloc(n * sizeof(int*));
//	for (int i = 0; i < n; i++) {
//		matA[i] = (int*)malloc(n * sizeof(int));
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			svyaz = rand() % 2;
//			matA[i][j] = svyaz;
//			matA[j][i] = svyaz;
//		}
//	}
//
//	printf("Матрица А:\n");
//	print(matA, n, n);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			if (matA[i][j] == 1) {
//				cou++;
//			}
//		}
//	}
//	printf("\nРазмер графа G: %d\n", cou);
//	
//	int versh = 0;
//	int k = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (matA[i][j] != 1) {
//				k++;
//			}
//		}
//		if (k == n) {
//			printf("\nИзолированная вершина: %d\n", versh + 1);
//		}
//		if ((n - k) == 1) {
//			printf("\nКонцевая вершина: %d\n", versh + 1);
//		}
//		if (k == 0) {
//			printf("\nДоминирующая вершина: %d\n", versh + 1);
//		}
//		versh++;
//		k = 0;
//	}
//	
//	return 0;
//}