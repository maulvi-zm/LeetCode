class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>> heap;
  int k = 0;

  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    for (auto num : nums) {
      this->add(num);
    }
  }

  int add(int val) {
    this->heap.push(val);
    if (heap.size() > k) {
      heap.pop();
    }

    return heap.top();
  }
};
