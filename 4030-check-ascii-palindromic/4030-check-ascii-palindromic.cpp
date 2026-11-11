class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.size();
        string bin="";
        for(char c:s){ int x=(int)c;

        for(int i=7;i>=0;i--){
            if(x&(1<<i)) bin+='1';
            else bin+='0';
        }
                     }
        int j=bin.size()-1;
    
        for(int i=0;i<bin.size()/2;i++){
            if(bin[i]!=bin[j]) return false;
            j--;
        }
        return true;
    }
};