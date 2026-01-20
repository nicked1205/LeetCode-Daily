class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastFruit = -1, secondLastFruit = -1;
        int lastFruitCnt = 0;
        int currWindow = 0;
        int maxx = 0;

        for(int f : fruits) {
            if (f == lastFruit || f == secondLastFruit) {
                currWindow++;
            } else {
                currWindow = lastFruitCnt + 1;
            }

            if (f == lastFruit) lastFruitCnt++;
            else lastFruitCnt = 1;

            if (f != lastFruit) {
                secondLastFruit = lastFruit;
                lastFruit = f;
            }
            maxx = max(maxx, currWindow);
        }
        return maxx;
    }
};