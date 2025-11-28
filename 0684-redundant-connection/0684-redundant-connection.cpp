class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 1);

        for (int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if (parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y){
            return false;
        }

        // Rank x > rank y
        if (rank[parent_y] > rank[parent_x]) swap(parent_x, parent_y);
        if (rank[parent_y] == rank[parent_x]) rank[parent_x] += 1;

        parent[parent_y] = parent_x;

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu = DSU(n);

        vector<int> ans;
        for (auto& edge: edges){
            if (!dsu.unite(edge[0], edge[1])){
                ans = edge;
            }
        }

        return ans;
    }
};