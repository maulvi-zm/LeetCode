class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre: prerequisites){
            int course = pre[0];
            int prereq = pre[1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        vector<int> res;

        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        
        int completed = 0;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            completed++;

            for (auto& neighbor: graph[curr]){
                indegree[neighbor]--;

                if (indegree[neighbor] == 0){
                    q.push(neighbor);
                    res.push_back(neighbor);
                }
            }
        }

        return completed == numCourses ? res : vector<int>();
        
    }
};