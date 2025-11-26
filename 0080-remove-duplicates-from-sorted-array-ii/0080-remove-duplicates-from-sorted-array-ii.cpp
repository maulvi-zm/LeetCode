class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, n = nums.size();

        for (int r = 0; r < n; r++){
            if (l < 2 || nums[r] != nums[l - 2]){
                nums[l++] = nums[r];
            }
        }

        return l;
    }
};