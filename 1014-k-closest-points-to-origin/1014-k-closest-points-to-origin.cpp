class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> heap;
    for (int i = 0; i < points.size(); i++) {
      auto point = points[i];
      auto distance = sqrt(pow(point[0], 2) + pow(point[1], 2));
      heap.push({distance, i});
    }

    vector<vector<int>> res;
    while (k--) {
      int i = heap.top().second;
      res.push_back(points[i]);
      heap.pop();
    }

    return res;
}
};