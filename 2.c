#include <stdio.h>
#include <stdlib.h>

int main() {
	size_t M, N;
	if (scanf("%ld %ld", &M, &N) != 2)
		return -1;
    if (M == 0 || N == 0)
        return -1;

	int** nums = (int**)malloc(sizeof(int*) * M + sizeof(int) * M * N);
	if (nums == NULL)
		return -2;

    nums[0] = (int*)(nums + M);
    for (size_t i = 1; i < M; i++)
        nums[i] = nums[0] + i * N;
	
	for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++)
            nums[i][j] = i * N + j + 1;
    }

	for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++)
            printf("%d ", nums[i][j]);
        printf("\n");
    }

	free(nums);
	return 0;
}
