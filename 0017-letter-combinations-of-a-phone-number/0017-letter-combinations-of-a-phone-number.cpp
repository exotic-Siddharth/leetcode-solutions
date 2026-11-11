class Solution {
public:
vector<string> result;
void solve(int ind,string &digits,string &temp,vector<string> &mp){
 if(ind==digits.size()){
    result.push_back(temp);
    return;
 }
  int digit=digits[ind]-'0';
 string letters=mp[digit];
       
        for (char ch : letters) {
            temp.push_back(ch);
            solve(ind + 1, digits, temp, mp);
            temp.pop_back(); 
        }

}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
    vector<string> mp={
      "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
  string temp="";
  solve(0,digits,temp,mp);
  return result;
    }
};