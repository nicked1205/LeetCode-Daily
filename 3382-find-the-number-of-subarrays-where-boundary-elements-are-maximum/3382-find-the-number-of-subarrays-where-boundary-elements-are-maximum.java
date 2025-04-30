class Solution {
    public long numberOfSubarrays(int[] nums) {
        int n = nums.length;
        int[] stack = new int[n];
        int top = -1;
        long subs = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i = n - 1; i >= 0; i--) {
            int curr = nums[i];
            while (top != -1 && stack[top] < curr)
                top--;

            int nextGreaterOrEqual = -1;
            if (top != -1)
                nextGreaterOrEqual = stack[top];

            stack[++top] = curr;

            if (nextGreaterOrEqual == -1)
                continue;

            int prevFreq = freq.getOrDefault(curr, 0);
            if (nextGreaterOrEqual == curr) {
                freq.put(curr, prevFreq + 1);
                subs += prevFreq + 1;
            } else if (prevFreq > 0)
                freq.put(curr, 0);
        }
        return subs + n;
    }
}