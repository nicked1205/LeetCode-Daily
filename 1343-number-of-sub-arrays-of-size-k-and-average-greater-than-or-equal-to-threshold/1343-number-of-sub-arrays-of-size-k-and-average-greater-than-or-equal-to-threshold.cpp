class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int res = 0;
        for (int i = 0; i < k; i++) {
            sum+=arr[i];
        }
        if (sum / k >= threshold) res++;

        int i = 1;
        int j = i + k - 1;

        while (j < n) {
            sum -= arr[i - 1];
            sum += arr[j];
            i++;
            j++;
            if (sum / k >= threshold) res++;
        }

        return res;
    }
};