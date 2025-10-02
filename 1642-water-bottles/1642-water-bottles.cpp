class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int curBottles = numBottles;
        int res = 0;
        while (curBottles >= numExchange) {
            res += numExchange;
            curBottles += 1 - numExchange;
        }
        res += curBottles;
        return res;
    }
};