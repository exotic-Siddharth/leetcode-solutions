class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=numbers.size()-1;
       int j = 0;

        while (j < i) {

           long long sum=numbers[i]+numbers[j];
           if(sum==target) return {j+1,i+1};
           else if(sum>target) i--;
           else j++;
      
        }
       return {}; 
    }
};