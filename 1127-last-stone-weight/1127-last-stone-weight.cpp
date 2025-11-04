class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> queue;
    for (auto stone : stones) {
      queue.push(stone);
    }

    while (queue.size() > 1) {
      int x = queue.top();
      queue.pop();
      int y = queue.top();
      queue.pop();

      int tmp = abs(x - y);
      if (tmp != 0) {
        queue.push(tmp);
      }
    }

    if (queue.empty())
      return 0;

    return queue.top();
  }
};
