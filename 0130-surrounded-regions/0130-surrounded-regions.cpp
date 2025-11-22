class Solution {
public:
    void dfs(vector<vector<bool>> &visited, vector<vector<char>>& board, int i, int j){

        if (visited[i][j]) return;

        int m = board.size(), n = board[0].size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1,0}};
        
        stack<pair<int, int>> s;

        s.push({i, j});
        while(!s.empty()){
            auto [r, c] = s.top();
            s.pop();

            visited[r][c] = true;

            for (auto& [dr, dc] : dirs){
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && board[nr][nc] == 'O'){
                    s.push({nr, nc});
                }
            }
        }
    };

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            if (i == 0 || i == m - 1) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'O') {
                        dfs(visited, board, i, j);
                    }
                }
            } else {
                if (board[i][0] == 'O') {
                    dfs(visited, board, i, 0);
                }

                if (board[i][n - 1] == 'O') {
                    dfs(visited, board, i, n - 1);
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};