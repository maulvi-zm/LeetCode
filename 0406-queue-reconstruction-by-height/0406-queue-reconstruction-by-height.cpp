class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto& pip : people) {
            pq.push({pip[0], pip[1]});
        }

        vector<vector<int>> res(n, {-1, -1});
        while (!pq.empty()) {
            auto [h, k] = pq.top();
            pq.pop();

            int counter = 0;
            int pos = 0;
            for (; pos < n; pos++) {
                if (res[pos][0] == -1 || res[pos][0] >= h)
                    counter++;
                if (counter == k + 1)
                    break;
            }

            cout << pos << h << k << endl;
            res[pos][0] = h;
            res[pos][1] = k;
        }

        return res;
    }
};