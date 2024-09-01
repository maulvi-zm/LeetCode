class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        bool negative = x < 0;

        if (negative) {
            if ((long long) x * -1 > INT_MAX) return 0;
            x *= -1;
        }

        while (x > 0){
            if ((long long) ans * 10 > INT_MAX){
                return 0;
            }
            ans *= 10;

            if ((long long) ans + (x % 10) > INT_MAX){
                return 0;
            }
            ans += x % 10;

            x /= 10;
        }

        if (negative) ans *= -1;

        return ans;
    }
};