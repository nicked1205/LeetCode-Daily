class Solution {
    long count;

    public Solution() {
        count = 0;
    }

    public long countSubarrays(int[] nums, long k) {
        if (k <= 0) return 0; 
        int i = 0;
        long sum = 0;
        for (int j = 0; j < nums.length; j++) {
            sum += nums[j];
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
        }
        return count;
    }
}