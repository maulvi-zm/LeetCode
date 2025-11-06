class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int total_minutes = 0;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                } else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while (!q.empty()) {
            int queue_size = q.size();
            for (int i = 0; i < queue_size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto &[dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        fresh--;
                    }
                }
            }

            total_minutes++;
        }

        return fresh > 0 ? -1 : max(total_minutes - 1, 0); 
    }
};
