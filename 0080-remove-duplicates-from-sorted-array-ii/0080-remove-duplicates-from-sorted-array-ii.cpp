class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, n = nums.size();

        int count = 1;
        for (int r = 1; r < n; r++){
            if (nums[r] != nums[r-1]){
                nums[++l] = nums[r];
                count = 1;
            } else if (count < 2){
                nums[++l] = nums[r];
                count++;
            }
        }

        return l + 1;
    }
};