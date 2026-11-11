class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 0; i + 1 < words.size(); i++) {
            if (!inCorrectOrder(words[i], words[i + 1], rank)) {
                return false;
            }
        }
        return true;
    }

private:
    bool inCorrectOrder(const string& a, const string& b, const vector<int>& rank) {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                return rank[a[i] - 'a'] < rank[b[i] - 'a'];
            }
        }
        return a.size() <= b.size();
    }
};
