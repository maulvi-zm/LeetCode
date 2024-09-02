class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;

       sort(nums.begin(), nums.end());


       for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1, right = nums.size() - 1, target = -nums[i];

            while (left < right){
                int sum = nums[left] + nums[right];

                if (sum == target){
                    vector<int> temp;

                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);

                    ans.push_back(temp);

                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                } else if (sum < target){
                    left++;
                } else{
                    right--;
                }
            }
       }

       return ans;
    }
};