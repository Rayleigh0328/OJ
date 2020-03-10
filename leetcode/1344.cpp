class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = (hour % 12) * 60 + minutes;
        double d1 = x /60.0 * 360/12;
        double d2 = minutes / 60.0 * 360;
        double ans = abs(d2-d1);
        if (ans > 180) ans = 360-ans;
        return ans;
    }
};
