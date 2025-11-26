class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r){
            while (r > 0 && !isalnum(s[r])){
                r--;
            }

            while (l < s.size() - 1 && !isalnum(s[l])){
                l++;
            }

            if (l > r){
                break;
            }

            if (tolower(s[r]) != tolower(s[l])){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};