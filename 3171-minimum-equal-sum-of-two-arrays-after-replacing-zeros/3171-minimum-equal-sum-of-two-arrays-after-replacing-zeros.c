long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long sum1 = 0;
    long sum2 = 0;
    long minSum1 = 0;
    long minSum2 = 0;

    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] == 0) minSum1++;
        else {
            sum1+=nums1[i];
            minSum1+=nums1[i];
        }
    }

    for (int j = 0; j < nums2Size; j++) {
        if (nums2[j] == 0) minSum2++;
        else {
            sum2+=nums2[j];
            minSum2+=nums2[j];
        }
    }
    printf("sum1: %d, sum2: %d, minSum1: %d, minSum2: %d\n", sum1, sum2, minSum1, minSum2);
    if ((sum1 == minSum1 && sum1 < minSum2) || (sum2 == minSum2 && sum2 < minSum1)) return -1;

    if (minSum1 < minSum2) return minSum2;
    return minSum1;
}