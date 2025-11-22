class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public: 
    DSU(int n){
        rank.resize(n, 0);
        parent.resize(n, 0);

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if (parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y){
            if (rank[root_x] < rank[root_y]){
                parent[root_x] = root_y;
            } else if (rank[root_x] > rank[root_y]){
                parent[root_y] = root_x;
            } else {
                parent[root_x] = root_y;
                rank[root_y]++;
            }
        }
    }

    int getTotalRoot(){
        int res = 0;
        for (int i = 0; i < parent.size(); i++){
            if (parent[i] == i) res++;
        }

        return res;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m  = isConnected.size(), n = isConnected[0].size();
        DSU dsu = DSU(m);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (isConnected[i][j] == 1){
                    dsu.unite(i, j);
                }
            }
        }

        return dsu.getTotalRoot();
    }
};