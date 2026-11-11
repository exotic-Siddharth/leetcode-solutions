class Solution {
public:
    string reverseByType(string s) {
        vector<char> alpha,spcl;
        for(char ch:s){
            if(islower(ch)){
                alpha.push_back(ch);
            }
            else
                spcl.push_back(ch);
        }
        reverse(alpha.begin(),alpha.end());
        reverse(spcl.begin(),spcl.end());
        
         int al = 0, sp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = alpha[al++];
            else
                s[i] = spcl[sp++];
        }
        
        return s;
    }
};