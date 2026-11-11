class Solution {
public:
    int finalElement(vector<int>& nums) {
        vector<int> arr=nums;
          int n=arr.size();
        if(n==1) return arr[0];
     return max(arr[0],arr[n-1]);
    }
};