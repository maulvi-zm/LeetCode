class DSU {
    private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        unordered_map<int, int> size;
    public:
        DSU(){};

        int find(int x){
            if (parent[x] == x){
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        void add(int x){
            if (parent.count(x) == 0){
                parent[x] = x;
                rank[x] = 0;
                size[x] = 1;
            }
            
            if (parent.count(x + 1) != 0){
                unite(x, x + 1);
            }

            if (parent.count(x - 1) != 0){
                unite(x, x - 1);
            }
        }

        void unite(int x, int y){
            int root_x = find(x);
            int root_y = find(y);

            if (root_x != root_y){
                if (rank[root_x] < rank[root_y]){
                    parent[root_x] = root_y;
                    size[root_y] += size[root_x];
                } else if (rank[root_x] < rank[root_y]){
                    parent[root_y] = root_x;
                    size[root_x] += size[root_y];
                } else {
                    parent[root_y] = root_x;
                    rank[root_x]++;
                    size[root_x] += size[root_y];
                }
            }
        }

        int longest(){
            int longest = INT_MIN;
            for (auto &[k, v] : size){
                longest = max(v, longest);
            }

            return longest;
        }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        DSU dsu = DSU();

        for (auto &num: nums){
            dsu.add(num);
        }

        return dsu.longest();
    }
};