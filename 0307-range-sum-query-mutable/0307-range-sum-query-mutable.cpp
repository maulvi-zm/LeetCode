class NumArray {
private:
    int n;
    vector<int> tree;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n, 0);

        for (int i = 0; i < n; i++){
            tree[i+n] = nums[i];
        }

        for (int i = n - 1; i > 0; i--){
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    void update(int index, int val) {
        int pos = index + n;
        tree[pos] = val;

        for (pos /= 2; pos > 0; pos /= 2){
            tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
        }
    }
    
    int sumRange(int left, int right) {
        int l = left + n;
        int r = right + n;

        int res = 0;
        while (l <= r){
            if (l % 2 == 1){
                res += tree[l];
                l++;
            }

            if (r % 2 == 0){
                res += tree[r];
                r--;
            }

            l /= 2;
            r /= 2;
        }

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */