class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            if (area > res) res = area;

            if (height[i] < height[j]) i += 1;
            else if (height[i] >= height[j]) j -= 1;
        }

        return res;
    }
};