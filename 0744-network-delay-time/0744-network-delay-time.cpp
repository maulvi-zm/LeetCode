class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        for (auto el: times){
            adj[el[0]].push_back({el[1], el[2]});
        }

        pq.push({0, k});
        while (!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();

            if (d != dist[u]) continue;

            for (auto &[v, w]: adj[u]){
                if (d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_dist = INT_MIN;
        for (int i = 1; i < n + 1; i++){
            if (dist[i] == INT_MAX){
                return -1;
            }

            max_dist = max(max_dist, dist[i]);
        }

        return max_dist;
    }
};