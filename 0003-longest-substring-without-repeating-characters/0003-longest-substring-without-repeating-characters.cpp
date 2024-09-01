class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;

        std::map<char, int> arr;
        int maximum = 1;

        int left = 0, right = 1;

        arr[s[left]] = left;
        while (right < s.length()){
            if (arr.find(s[right]) != arr.end()){
                left = max(arr[s[right]] + 1, left);
            }

            maximum = max(right - left + 1, maximum);
            arr[s[right]] = right;
            right++;
        }

        maximum = max(right - left, maximum);

        return maximum;
    }
};
 