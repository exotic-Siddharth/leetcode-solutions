class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int count1=0,count2=0,ans=0;
       for(char ch:s){
            if(ch=='0') count1++;
            else count2++;
            
            if(abs(count1-count2)<=1) ans++;
            
        }
        return ans;
    }
};