/* ИМЯ: Степан Григорьев КВБО-07-22 22К0476 */
/* СРОК : 02/11/2024 */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ Выделение памяти под двумерный массив из M * N целых чисел */
/* ИМЯ ФАЙЛА: 2.c */
/*
Считывает M, N из потока ввода и проверяет на корректность.
Выделяет память под двумерный массив, инициализирует его
и заполняет его значениями, потом выводит содержимое массива
и чистит память. 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t M, N;
    if (scanf("%ld %ld", &M, &N) != 2) return -1;
    if (M == 0 || N == 0) return -1;

    int** nums = (int**)malloc(sizeof(int*) * M + sizeof(int) * M * N);
    if (nums == NULL) return -2;

    nums[0] = (int*)(nums + M);
    for (size_t i = 1; i < M; i++) nums[i] = nums[0] + i * N;

    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) nums[i][j] = i * N + j + 1;
    }

    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) printf("%d ", nums[i][j]);
        printf("\n");
    }

    free(nums);
    return 0;
}
