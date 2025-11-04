class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>> heap;
        for (int i = 0; i < points.size(); i++) {
            auto point = points[i];
            auto distance = sqrt(pow(point[0], 2) + pow(point[1], 2));
            heap.push({distance, i});

            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<vector<int>> res;
        while (k--) {
            res.push_back(points[heap.top().second]);
            heap.pop();
        }

        return res;
    }
};