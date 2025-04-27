class Solution {
    int count;

    public Solution() {
        count = 0;
    }

    public int countSubarrays(int[] nums) {
        int i = 0;
        while (i < nums.length - 2) {
            if (testSubarray(nums[i], nums[i + 1], nums[i + 2])) {
                count++;
            }
            i++;
        }
        return count;
    }

    public boolean testSubarray(int a, int b, int c) {
        return (double) a + (double) c == (double) b / 2;
    }
}