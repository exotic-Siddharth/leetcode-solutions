class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (int i = 0; i < words.size(); i++) {
            int sum = 0;

            for (int j = 0; j < words[i].size(); j++) {
                sum = (sum + weights[words[i][j] - 'a']) % 26;
            }

            ans.push_back('a' + (25 - sum));
        }

        return ans;
    }
};