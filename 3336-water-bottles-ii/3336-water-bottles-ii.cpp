#include <iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int i = numExchange;
        int curBottles = numBottles;
        int res = 0;
        while (curBottles >= i) {
            res += i;
            curBottles += 1 - i;
            i += 1;
        }
        res += curBottles;
        return res;
    }
};