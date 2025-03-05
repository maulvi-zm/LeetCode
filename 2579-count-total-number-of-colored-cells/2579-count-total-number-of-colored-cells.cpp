class Solution {
public:
    long long coloredCells(int n) {
        long long long_n = n; 
        return 2 * long_n * long_n - 2 * long_n + 1;
    }
};

// 1 5 13 25 
//  4 8 12
//   4 4


// 1 + (n-1)*4 + (n-1)(n-2)*2 
// 1 + 2n^2 - 2n

// 2n^2 - 2n + 1
