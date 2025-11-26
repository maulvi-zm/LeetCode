class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, max_area = 0;

        while (l < r){
            int min_h = min(height[r], height[l]);
            max_area = max((r - l) * min_h, max_area);

            if (height[r] < height[l]){
                r--;
            } else {
                l++;
            }
        }

        return max_area;
    }
};