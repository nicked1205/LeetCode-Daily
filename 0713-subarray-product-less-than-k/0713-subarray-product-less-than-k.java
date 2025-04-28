class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;        
        int count = 0;
        int i = 0;
        long prod = 1;        
        for (int j = 0; j < nums.length; j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            count += j - i + 1;
        }
        return count;
    }
}