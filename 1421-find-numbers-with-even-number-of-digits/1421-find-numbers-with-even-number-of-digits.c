#include <stdio.h>
#include <string.h>

int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        char str[10];
        sprintf(str, "%d", nums[i]);
        if (strlen(str) % 2 == 0) count++;
    }
    return count;
}