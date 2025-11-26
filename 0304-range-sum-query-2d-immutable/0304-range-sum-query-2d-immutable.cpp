class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++){
            int sum = 0;
            for (int j = 0; j < matrix[0].size(); j++){
                sum += matrix[i][j];

                int add = sum;
                if (i > 0){
                    add += prefix[i-1][j];
                }
                
                prefix[i][j] = add;
            }
        }

        for (auto row: prefix){
            for (auto num: row){
                cout << num << " ";
            }

            cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > 0 && col1 > 0){
            return prefix[row2][col2] - prefix[row1-1][col2] - prefix[row2][col1-1] + prefix[row1-1][col1-1];
        } else if (row1 == 0 && col1 == 0){
            return prefix[row2][col2];
        } else if (row1 == 0){
            return prefix[row2][col2] - prefix[row2][col1-1];
        } else {
            return prefix[row2][col2] - prefix[row1-1][col2];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */