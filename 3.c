/* ИМЯ: Степан Григорьев КВБО-07-22 22К0476 */
/* СРОК : 02/11/2024 */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ Поиск количества простых чисел и минимального числа массива */
/* ИМЯ ФАЙЛА: 3.c */
/*
Программа на C считывает количество чисел и сами числа, затем определяет,
сколько из них являются простыми, а также находит минимальное число среди введенных.
 */

#include <stdio.h>
#include <stdlib.h>

int simple_count(int* nums, size_t size, int* min_num);
int max(int first, int second);
int min(int first, int second);

int main() {
    size_t N;
    int min_res, count;
    if (scanf("%ld", &N) != 1) return -1;
    if (N == 0) return -1;

    int* nums = (int*)malloc(sizeof(int) * N);
    if (nums == NULL) return -2;

    for (size_t i = 0; i < N; i++) {
        if (scanf("%d", nums + i) != 1) {
            free(nums);
            return -3;
        }
    }

    count = simple_count(nums, N, &min_res);
    if (count >= 0) {
        printf("Simple count : %d\nMin : %d", count, min_res);
    }

    free(nums);
    return 0;
}

//Основная функция поиска (работает через решето Эратосфена)
int simple_count(int* nums, size_t size, int* min_num) {
    *min_num = nums[0];
    int max_num = nums[0], *simple_nums, count = 0;

    for (size_t i = 1; i < size; i++) {
        max_num = max(max_num, nums[i]);
        *min_num = min(*min_num, nums[i]);
    }

    if (max_num <= 1) return 0;

    simple_nums = (int*)calloc(max_num + 1, sizeof(int));
    if (simple_nums == NULL) return -1;

    for (size_t i = 2; i < (size_t)max_num; i++) {
        if (simple_nums[i]) continue;
        for (size_t j = i * 2; j <= (size_t)max_num; j += i) {
            simple_nums[j] = 1;
        }
    }

    for (size_t i = 0; i < size; i++) {
        if (nums[i] <= 1) continue;
        count += (!simple_nums[nums[i]]);
    }

    free(simple_nums);
    return count;
}

//Максимум двух чисел
int max(int first, int second) {
    if (first > second) return first;
    return second;
}

//Минимум двух чисел
int min(int first, int second) {
    if (first < second) return first;
    return second;
}