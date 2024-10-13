#include <stdio.h>
#include <stdlib.h>

int main() {
	size_t N;
	if (scanf("%ld", &N) != 1)
		return -1;

	int* nums = (int*)malloc(sizeof(int) * N);
	if (nums == NULL)
		return -2;
	
	for (size_t i = 0; i < N; i++)
		nums[i] = i + 1;

	for (size_t i = 0; i < N; i++)
		printf("%d ", nums[i]);

	free(nums);
	return 0;
}