class NumMatrix {
    private:
        vector<vector<int>> prefix;
    public:
        NumMatrix(vector<vector<int>>& matrix) {

            for (int i = 0; i < matrix.size(); i++){
                vector<int> row;
                int temp = 0;

                for (int j = 0; j < matrix[i].size(); j++){
                    temp += matrix[i][j];
                    row.push_back(temp);

                    if (i > 0){
                        row[j] += prefix[i-1][j];
                    }
                }

                prefix.push_back(row);
            }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            int left_down = row1 > 0 ? prefix[row1-1][col2] : 0;
            int right_up = col1 > 0 ? prefix[row2][col1-1] : 0;
            int corner = (row1 > 0 && col1 > 0) ? prefix[row1-1][col1-1] : 0;

            return prefix[row2][col2] - left_down - right_up + corner;
        }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */