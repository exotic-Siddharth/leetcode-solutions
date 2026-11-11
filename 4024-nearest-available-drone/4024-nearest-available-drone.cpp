class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int mn=INT_MAX;
        int ind=-1;
        for(int i=0;i<n;i++){
               int dis=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(dis<=drones[i][2]){
            if(dis<mn){
                mn=dis;
                ind=i;
            }
            }
        }
        return ind;
    }
};