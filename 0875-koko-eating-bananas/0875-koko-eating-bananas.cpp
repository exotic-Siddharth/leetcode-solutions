class Solution {
public:
long long CaltotalHrs(vector<int>& piles,int mid){
     long long totalhrs=0;
     for(int i=0;i<piles.size();i++){
        totalhrs+=ceil((double)piles[i]/(double)mid);
     }
     return totalhrs;

}


int findMax(vector<int>& piles){
    int mx=INT_MIN;
    for(int i=0;i<piles.size();i++) mx=max(mx,piles[i]);
    return mx;
}
    int minEatingSpeed(vector<int>& piles, int h) {
           
        int low=1,high=findMax(piles);
          int ans=0;
        while(low<=high){
            int mid=(high-low)/2+low;
           long long totalhrs= CaltotalHrs(piles,mid);
         
            if(totalhrs<=h){
              ans=mid;
              high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};