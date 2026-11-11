class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min(abs(30*hour+0.5*minutes-6*minutes),360-abs(30*hour+0.5*minutes-6*minutes));
    }
};