class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, pair<unordered_set<int>, unordered_set<int>>> m;
        vector<bool> visited(numCourses, false);
        queue<int> q;

        // Find the start point
        for (auto& relation : prerequisites){
            if (m.count(relation[1]) == 0){
                m.insert({relation[1], {unordered_set<int>(), unordered_set<int>()}});
            }

            if (m.count(relation[0]) == 0){
                m.insert({relation[0], {unordered_set<int>(), unordered_set<int>()}});
            }

            // It can be used to finish a course
            m[relation[1]].first.insert(relation[0]);

            // The target course need this as prereq
            m[relation[0]].second.insert(relation[1]);
        }

        // Add the start point to the queue
        for (int i = 0; i < numCourses; i++){
            if (m[i].second.size() == 0){
                q.push(i);
            }
        }

        // No start point
        if (q.empty()){
            return false;
        }

        int completed = 0;
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            completed++;

            // Loop towards the next course that can be completed
            for (auto& neighbor: m[curr].first){
                // If this node is completed, then all next node needs to remove the prereq 
                if (m[curr].second.size() == 0){
                    m[neighbor].second.erase(curr);
                }

                if (m[neighbor].second.size() == 0){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return completed == numCourses;
    }
};