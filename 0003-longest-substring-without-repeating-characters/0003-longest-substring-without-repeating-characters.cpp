class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int left=0,maxlen=0;
        for (int i=0;i<s.size();i++){
            if(hash[s[i]]>=left) left=hash[s[i]]+1;
            hash[s[i]]=i;
            maxlen=max(maxlen,i-left+1);
        }
        return maxlen;
    }
};