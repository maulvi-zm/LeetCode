class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int arr[n+1];
        memset(arr, 0, sizeof(arr));

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for (int i = 3; i <= n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }
};

