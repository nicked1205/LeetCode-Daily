class Solution {
public:
    vector<int> sat = {
        1, 3, 7, 15, 31, 63, 127, 255, 511, 1023
    };

    int smallestNumber(int n) {
        int s = sat.size();
        int mid = s / 2;
        int lo = 0;
        int hi = s - 1;

        while (lo <= hi) {
            if (sat[mid] < n) lo = mid + 1;
            else if (sat[mid] > n) hi = mid - 1;
            else return n;

            mid = (lo + hi) / 2;
        }

        if (lo >= s)
            return sat.back();
        return sat[lo];
    }
};