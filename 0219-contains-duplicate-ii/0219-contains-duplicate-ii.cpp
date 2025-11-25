class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int left = 0;
        s.insert(nums[left]);

        for (int right = 1; right < nums.size(); right++){
            if (right - left > k){
                s.erase(nums[left]);
                left++;
            };
            
            if (s.count(nums[right])){
                return true;
            }

            s.insert(nums[right]);
        }

        return false;
    }
};