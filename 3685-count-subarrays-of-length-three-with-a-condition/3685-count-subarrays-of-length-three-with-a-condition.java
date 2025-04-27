import java.util.*;

class Solution {
    int count;

    public Solution() {
        count = 0;
    }

    public int countSubarrays(int[] nums) {
        int i = 0;
        while (i < nums.length - 2) {
            System.out.println(nums[i]);
            if (testSubarray(Arrays.copyOfRange(nums, i, i + 3))) {
                System.out.println("True");
                count ++;
            }
            i += 1;
        }
        return count;
    }

    public boolean testSubarray(int[] subArr) {
        System.out.println(subArr[0] + subArr[2]);
        if ((double)subArr[0] + (double)subArr[2] == (double)subArr[1] / 2) {
            return true;
        }
        return false;
    }
}