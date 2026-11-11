class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1) return 0;

        if (n > 1 && m > 1 && grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (time > dist[row][col]) continue;
            if (row == n - 1 && col == m - 1) return time;

            for (int i = 0; i < 4; i++) {
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nt = time + 1;

                    if (nt < grid[nr][nc]) {
                        int wait = grid[nr][nc] - nt;
                        nt = grid[nr][nc] + (wait % 2);
                    }

                    if (nt < dist[nr][nc]) {
                        dist[nr][nc] = nt;
                        pq.push({nt, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
