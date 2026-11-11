class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // unordered_map<char,int> freq;
        int cntb=0;
        int cnta=0;
        int cntl=0;
        int cnto=0;
        int cntn=0;
        for(int i=0;i<text.size();i++){
            if(text[i]=='b') cntb++;
            else   if(text[i]=='a') cnta++;
            else   if(text[i]=='l') cntl++;
             else   if(text[i]=='o') cnto++;
              else   if(text[i]=='n') cntn++;
        }
        return min({cntb, cnta, cntl / 2, cnto / 2, cntn});
    }
};