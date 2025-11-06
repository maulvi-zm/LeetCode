class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> queue;

        int dirs[8][2] = {{1, 0}, {-1, 0},  {0, -1}, {0, 1},
                          {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

        int shortest_length = 0;

        if ((grid[0][0] == 0) && grid[m-1][n-1] == 0)
            queue.push({0, 0});

        while (!queue.empty()) {
            int queue_size = queue.size();
            for (int i = 0; i < queue_size; i++) {
                auto [r, c] = queue.front();
                queue.pop();

                if (r == m - 1 && c == n - 1) {
                    return shortest_length + 1;
                }

                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                        grid[nr][nc] == 0 && !visited[nr][nc]) {
                        queue.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }

            shortest_length++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
