class Solution {
public:
    int lengthOfLastWord(string s) {
       int count=0;
       bool started=false;
       for(int i=s.size()-1;i>=0;i--){
        if(s[i]!=' ') {
            count++;
            started=true;
       }
       else if(started) break;
       }
       return count;
    }
};