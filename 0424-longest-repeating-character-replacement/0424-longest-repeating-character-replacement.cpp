class Solution {
public:
    int characterReplacement(string s, int k) {
        
       int l=0,r=0,maxF=0,maxL=0;
       vector<int> mpp(26,0);
       while(r<s.size()){
            mpp[s[r]-'A']++;
            maxF=max(maxF,mpp[s[r]-'A']);
            while((r-l+1)-maxF>k){
                mpp[s[l]-'A']--;
                l++;
                maxF=0;
               for(int i=0;i<26;i++) maxF=max(maxF,mpp[i]);
            }
            if((r-l+1)-maxF<=k){
                maxL=max(maxL,r-l+1);
            }
            r++;
       }
       return maxL;
        
    }
};