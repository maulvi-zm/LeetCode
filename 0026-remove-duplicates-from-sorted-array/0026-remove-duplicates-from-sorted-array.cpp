class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, n = nums.size();

        for (int r = 1; r < n; r++){
            if (nums[r] != nums[r-1]){
                nums[++l] = nums[r];
            }
        }

        return l + 1;
    }
};