class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
            int& total_walkable_square, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int count = 0;

        if (grid[r][c] == -1 || visited[r][c]) {
            return 0;
        }

        visited[r][c] = true;
        total_walkable_square--;
        if (grid[r][c] == 2) {
            visited[r][c] = false;
            if (total_walkable_square == 0){
                total_walkable_square++;
                return 1;
            }

            total_walkable_square++;
            return 0;
        }

        for (auto& [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                count += dfs(grid, visited, total_walkable_square, nr, nc);
            }
        }

        visited[r][c] = false;
        total_walkable_square++;

        return count;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Find total walkable square and the end square
        int total_walkable_square = 0;
        pair<int, int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    total_walkable_square++;
                if (grid[i][j] == 1)
                    start = {i, j};
            }
        }

        return dfs(grid, visited, total_walkable_square, start.first,
                   start.second);
    }
};