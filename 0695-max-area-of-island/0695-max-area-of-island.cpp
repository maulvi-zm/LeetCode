class Solution {
public:
  int areaofIsland(vector<vector<int>> &grid, int row, int col) {
    int n = grid.size(), m = grid[0].size();
    stack<pair<int, int>> stack;
    int area = 0;

    int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    stack.push({row, col});
    while (!stack.empty()) {
      auto [r, c] = stack.top();
      stack.pop();
      if (grid[r][c] == 1) {
        area++;
        grid[r][c] = 0;
      }

      for (auto &[x, y] : dirs) {
        int next_r = x + r, next_c = y + c;
        if (next_r >= 0 && next_r < grid.size() && next_c >= 0 &&
            next_c < grid[0].size() && grid[next_r][next_c] == 1) {
          stack.push({next_r, next_c});
        }
      }
    }

    return area;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          int area = areaofIsland(grid, i, j);
          maxArea = max(area, maxArea);
        }
      }
    }

    return maxArea;
  }
};
