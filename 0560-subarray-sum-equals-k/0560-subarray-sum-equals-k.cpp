class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int temp = 0;
        vector<int> prefix; 

        for (int i = 0; i < nums.size(); i++){
            temp += nums[i];
            prefix.push_back(temp);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (prefix[i] == k) ans++;

            for (int j = i + 1; j < nums.size(); j++){
                if ((prefix[j] - prefix[i]) == k) ans++;
            }
        }

        return ans;
    }
};