class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,r=0;
        int mx=INT_MIN;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
         mx=max(mx,r-l+1);
         r++;
        }
        return mx;
    }
};