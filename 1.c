/* ИМЯ: Степан Григорьев КВБО-07-22 22К0476 */
/* СРОК : 02/11/2024 */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ Выделение памяти под массив из N целых чисел */
/* ИМЯ ФАЙЛА: 1.c */
/*
Считывает N из потока ввода и проверяет на корректность.
Выделяет память под массив и заполняет его значениями, потом выводит содержимое массива
и чистит память. 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t N;
    if (scanf("%ld", &N) != 1) return -1;

    int* nums = (int*)malloc(sizeof(int) * N);
    if (nums == NULL) return -2;

    for (size_t i = 0; i < N; i++) nums[i] = i + 1;

    for (size_t i = 0; i < N; i++) printf("%d ", nums[i]);

    free(nums);
    return 0;
}
