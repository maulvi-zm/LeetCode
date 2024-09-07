class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int temp = 0;
        for (int i = 0; i < nums.size(); i++){
            temp += nums[i];
            prefix.push_back(temp);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */