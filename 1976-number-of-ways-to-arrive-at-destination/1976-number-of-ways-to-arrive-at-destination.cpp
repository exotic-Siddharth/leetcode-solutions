class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int mod = 1000000007;

        vector<pair<long long,long long>> adj[n];

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        > pq;

        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dis[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){

            long long d = pq.top().first;
            long long u = pq.top().second;
            pq.pop();

            if(d > dis[u])
                continue;

            for(auto it : adj[u]){

                long long v = it.first;
                long long time = it.second;

                if(d + time < dis[v]){

                    dis[v] = d + time;
                    ways[v] = ways[u];

                    pq.push({dis[v], v});
                }
                else if(d + time == dis[v]){

                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};