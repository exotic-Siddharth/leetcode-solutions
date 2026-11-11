class Solution {
public:
    int passwordStrength(string password) {
        string pswrd=password;
        unordered_set<char> st;
        int strength=0;
        for(char ch: pswrd){
            if(st.count(ch)) continue;
            st.insert(ch);
             if(ch >= 'a' && ch <= 'z') {
                strength += 1;
            }
             if(ch >= 'A' && ch <= 'Z') {
                strength += 2;
            }
             if(ch >= '0' && ch <= '9') {
                strength += 3;
            }
            else if(ch == '!' || ch == '@' ||
                    ch == '#' || ch == '$') {

                strength += 5;
            }
        }
        return strength;
    }
};