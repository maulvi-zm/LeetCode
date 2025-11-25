class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, ans = 0;
        vector<int> counter(26, 0);

        for (int i = 0; i < s.size(); i++) {
            counter[s[i] - 'A']++;

            int maxLen = 0;
            for (auto& num : counter) {
                maxLen = max(maxLen, num);
            }

            if (i - l + 1 - maxLen > k) {
                counter[s[l] - 'A']--;
                l++;
            }

            ans = min(max(ans, maxLen + k), i - l + 1);
        }

        return ans;
    }
};