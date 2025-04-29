import java.util.ArrayList;

class Solution {
    public long countSubarrays(int[] nums, int k) {
        int max = 0;
        ArrayList<Integer> maxIndArr = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndArr.clear();
                maxIndArr.add(i);
            }
            else if (nums[i] == max) {
                maxIndArr.add(i);
            }
        }

        if (maxIndArr.size() < k) return 0;

        long resCount = 0;
        for (int i = 0; i <= maxIndArr.size() - k; i++) {
            long leftBound = (i == 0) ? maxIndArr.get(i) + 1 : maxIndArr.get(i) - maxIndArr.get(i - 1);
            long rightBound = nums.length - maxIndArr.get(i + k - 1);
            resCount += leftBound * rightBound;
        }

        return resCount;
    }
}