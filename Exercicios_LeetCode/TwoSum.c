#include <stdio.h>
#include <stdlib.h>

// Declaração da função twoSum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if ((nums[i] + nums[j]) == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;

    int* result = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);

    if (result != NULL) {
        printf("Índices encontrados: [%d, %d]\n", result[0], result[1]);
        free(result); // Libera a memória alocada
    } else {
        printf("Nenhuma combinação encontrada.\n");
    }

    return 0;
}
