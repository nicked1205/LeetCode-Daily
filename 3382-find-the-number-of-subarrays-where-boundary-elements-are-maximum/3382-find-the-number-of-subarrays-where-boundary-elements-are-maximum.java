class Solution {
    public long numberOfSubarrays(int[] nums) {
        int n = nums.length;
        // [1,4,3,4,2,4,5], top element of stack would always point to next greater or equal element to the right
        int[] stack = new int[n];
        int top = -1;
        long subs = 0;
        Map<Integer,Integer> freq = new HashMap<>();
        for(int i=n-1;i>=0;i--) {
            int curr = nums[i];
            // while top < curr, pop from stack
            while(top != -1 && stack[top] < curr)
                top--;
            
            int nextGreaterOrEqual = -1;
            if(top != -1)
                nextGreaterOrEqual = stack[top];

            stack[++top] = curr;

            if(nextGreaterOrEqual == -1)
                continue;

            // get previous freq of curr as a next greatest element
            int prevFreq = freq.getOrDefault(curr, 0);
            if(nextGreaterOrEqual == curr) {
                freq.put(curr, prevFreq + 1);
                subs += prevFreq + 1;
            }
            // remove previous appearances of current as next greatest if it currently fails to be the next greatest
            else if(prevFreq > 0)
                freq.put(curr, 0);
        }
        // 1-sized subarray are trivially valid (first and last are max)
        return subs + n;
    }
}