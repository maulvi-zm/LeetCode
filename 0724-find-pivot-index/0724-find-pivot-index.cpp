class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;

        int tmp = 0;
        for (auto &num: nums){
            tmp += num;
            prefix.push_back(tmp);
        }

        for (int i = 0; i < nums.size(); i++){
            int lsum = 0, rsum = 0;

            if (i > 0){
                lsum = prefix[i] - nums[i];
            }

            if (i < nums.size() - 1){
                rsum = prefix[nums.size()-1] - lsum - nums[i];
            }

            if (lsum == rsum){
                return i;
            }
        }

        return -1;
    }
};