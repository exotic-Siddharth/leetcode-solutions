class Solution {
public:
    int maxVowels(string s, int k) {

        int l = 0, r = k - 1;
        int count = 0;

    
        for(int i = l; i <= r; i++) {
            if(s[i] == 'a' || s[i] == 'e' || 
               s[i] == 'i' || s[i] == 'o' || 
               s[i] == 'u') {
                count++;
            }
        }

        int maxCount = count;

        while(r < s.size() - 1) {

            if(s[l] == 'a' || s[l] == 'e' || 
               s[l] == 'i' || s[l] == 'o' || 
               s[l] == 'u') {
                count--;
            }

            l++;
            r++;

            if(s[r] == 'a' || s[r] == 'e' || 
               s[r] == 'i' || s[r] == 'o' || 
               s[r] == 'u') {
                count++;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};