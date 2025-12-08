class SegmentTree{
private:
    int n;
    vector<int> tree;
public:
    SegmentTree(int max_num){
        n = max_num + 1;
        tree.resize(2 * n, 0);
    }

    void update(int num, int val){
        int idx = num + n;
        tree[idx] = val;

        while (idx > 1){
            idx /= 2;
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    int query(int left, int right){
        int res = 0;

        int l = left + n;
        int r = right + n;

        while (l <= r){
            if (l % 2 == 1){
                res = max(res, tree[l]);
                l++;
            }

            if (r % 2 == 0){
                res = max(res, tree[r]);
                r--;
            }

            l /= 2;
            r /= 2;
        }

        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int max_num = *max_element(nums.begin(), nums.end());
        SegmentTree tree(max_num);

        for (auto &num: nums){
           int new_len = tree.query(max(num - k, 1), num - 1) + 1;
           tree.update(num, new_len);
        }

        return tree.query(1, max_num);
    }
};