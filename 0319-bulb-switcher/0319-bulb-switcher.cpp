class Solution {
private:
    bool hasOddNumberOfFactors(long long n) {
        long long root = sqrt(n);
        return root * root == n;
    }
public:
    int bulbSwitch(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++){
            if (hasOddNumberOfFactors(i)){
                res++;
            }
        }

        return res;
    }
};