class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> freq;

        while(n > 0) {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }

        int score = 0;

        for(auto &it : freq) {
            score += it.first * it.second;
        }

        return score;
    }
};