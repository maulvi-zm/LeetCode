class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, 0, 0}); // w, r, c

        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();

            if (d != dist[r][c])
                continue;

            for (auto& [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int h_diff = max(d, abs(heights[nr][nc] - heights[r][c]));
                    if (h_diff < dist[nr][nc]) {
                        dist[nr][nc] = h_diff;
                        pq.push({h_diff, nr, nc});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};