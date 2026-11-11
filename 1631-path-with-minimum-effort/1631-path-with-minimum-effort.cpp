class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int effort = it[0];
            int r = it[1];
            int c = it[2];

            if(r == n-1 && c == m-1)
                return effort;

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m) {

                    int newEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));

                    if(newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({ newEffort, nr, nc });
                    }
                }
            }
        }

        return 0;
    }
};