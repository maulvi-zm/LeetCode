class Solution {
public:
    bool isPalindrome(string s) {
        string alnum = "";

        for (auto c: s){
            if (isalnum(c)){
                alnum += tolower(c);
            }
        }

        int l = 0, r = alnum.size() - 1;
        while (l <= r){
            if (alnum[r] != alnum[l]){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};