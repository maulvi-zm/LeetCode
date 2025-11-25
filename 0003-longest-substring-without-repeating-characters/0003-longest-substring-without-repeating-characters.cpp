class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, ans = 0;
        unordered_set<char> unique;

        for (int i = 0; i < s.size(); i++) {
            while (unique.count(s[i])){
                unique.erase(s[l]);
                l++;
            } 

            unique.insert(s[i]);
            ans = max((int) unique.size(), ans);
        }

        return ans;
    }
};