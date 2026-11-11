class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mpp;

        for(char ch : s) {
            mpp[ch]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto it : mpp) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ans += string(it.first, it.second);
        }

        return ans;
    }
};