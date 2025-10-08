class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int i = len - 1;
    	
        while (digits[i] == 9) {
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 0);
                break;
            }
            i--;
        }
        digits[i] += 1;

        return digits;
    }
};