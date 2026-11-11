class Solution {
public:
    string removeStars(string s) {
        stack<char> str;
        for(int i=0;i<s.size();i++){
           if(s[i]>='a' && s[i]<='z') str.push(s[i]);
           else if(s[i]=='*') str.pop();
        }
        string ans="";
        while(!str.empty()){
            ans+=str.top();
            str.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};