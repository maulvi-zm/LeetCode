class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        vector<long long> prevRow(n, 0);
        prevRow[n-1] = 1;

        for (int i = m-1; i >= 0; i--) {
            vector<long long> currRow(n, 0);

            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    currRow[j] = 0;
                    continue;
                }

                currRow[j] = (j != n - 1 ? currRow[j + 1] : 0) + prevRow[j];
            }

            prevRow = currRow;
        }

        return prevRow[0];
    }
};