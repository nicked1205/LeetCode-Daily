class Solution {
public:
    int bestClosingTime(string customers) {
        int pen = 0;
        for (char c : customers) {
            if (c == 'Y') pen++;
        }
        int minPen = pen;
        int minJ = 0;
        int j = 0;
        // cout << "j = " << j << " pen = " << pen << endl;
        while (j < customers.length()) {
            if (customers[j] == 'Y') pen--;
            else pen++;
            // cout << "j = " << j + 1 << " pen = " << pen << endl;
            if (pen < minPen) {
                minJ = j + 1;
                minPen = pen;
            }
            j++;
        }

        return minJ;
    }
};