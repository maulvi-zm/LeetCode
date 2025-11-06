class Solution {
public:
  void deleteIsland(vector<vector<char>> &grid, int row, int col) {
    if (row == grid.size() || col == grid[0].size() || row < 0 || col < 0)
      return;

    if (grid[row][col] == '0')
      return;

    if (grid[row][col] == '1')
      grid[row][col] = '0';

    deleteIsland(grid, row, col + 1);
    deleteIsland(grid, row + 1, col);
    deleteIsland(grid, row - 1, col);
    deleteIsland(grid, row, col - 1);
  }

  int numIslands(vector<vector<char>> &grid) {
    int num_of_islands = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1')
          num_of_islands++;
        deleteIsland(grid, i, j);
      }
    }
    return num_of_islands;
  }
};
