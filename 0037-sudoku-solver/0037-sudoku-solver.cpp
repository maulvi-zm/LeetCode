class Solution {
public:
    bool checkValid(int i, int j, char s, vector<vector<char>>& board){
        // search row
        for (int k = 0; k < board[0].size(); k++){
            if (board[i][k] == s) return false;
        }

        // search col
        for (int l = 0; l < board.size(); l++){
            if (board[l][j] == s) return false;
        }

        // search box
        for (int curr_row = (i / 3) * 3; curr_row <= ((i / 3) * 3 + 2); curr_row++){
            for (int curr_col = (j / 3) * 3; curr_col <= ((j / 3) * 3 + 2); curr_col++){
                if (board[curr_row][curr_col] == s) return false;
            }
        }

        return true;
    }

    bool solveHelper(int i, int j, vector<vector<char>>& board){
        if (j >= board[0].size()) return solveHelper(i + 1, 0, board);
        if (i >= board.size()) return true;
        if (board[i][j] != '.') return solveHelper (i, j + 1, board);

        // find earlist char that is valid in current state
        char curr = '1';

        do {
            while (!checkValid(i, j, curr, board)){
                curr++;

                if (curr > '9') {
                    board[i][j] = '.';
                    return false;
                };
            }

            board[i][j] = curr;
        } while(!solveHelper(i, j + 1, board));

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveHelper(0,0, board);
    }
};