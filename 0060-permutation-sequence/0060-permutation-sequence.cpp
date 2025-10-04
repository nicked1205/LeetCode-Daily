class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numArr;
        int x = k - 1;
        string res = "";
        int fact = 1;

        for (int i = 1; i < n; i++) {
            numArr.push_back(i);
            fact *= i;
        }
        numArr.push_back(n);

        while (true) {
            res += to_string(numArr[x / fact]);
            numArr.erase(numArr.begin() + x / fact);

            if (numArr.size() == 0){
                break;
            }

            x = x % fact;
            fact = fact / numArr.size();
        }
        return res;
    }
};