class Solution {
public:
    string longestPalindrome(string s) {
        for (int i = s.length(); i > 0; i--) {
            int current = 0;

            while (current + i - 1 < s.length()) {
                bool palindrom = true;

                int j = current, k = current + i - 1;
                while (palindrom && j <= k) {
                    if (s[j] != s[k]) {
                        palindrom = false;
                    }

                    j++;
                    k--;
                }

                if (palindrom) {
                    return s.substr(current, i);
                }

                current++;
            }
        }

        return "";
    }
};