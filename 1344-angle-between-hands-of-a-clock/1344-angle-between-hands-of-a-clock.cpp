class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour  = 0;
        double sec = (static_cast<double>(minutes) / 60 + hour) * 30;
        double res = abs(minutes * 6 - sec);
        return res <= 180 ? res : 360 - res;
    }
};