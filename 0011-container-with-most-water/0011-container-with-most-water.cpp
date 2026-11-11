class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int MaxArea=0;
        while(i<j){
      int currArea=(j-i)*min(height[i],height[j]);
      MaxArea=max(MaxArea,currArea);
      if(height[i]<height[j]) i++;
      else j--;
        }
        return MaxArea;
    }
};