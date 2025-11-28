class DSU{
private:
    vector<string> users;
    unordered_map<string, int> email_to_user;
    map<string, string> parent;
public:
    DSU(){}
    // Find user should return a Index

    string find(string word){
        if (parent[word] == word){
            return word;
        } 

        return parent[word] = find(parent[word]);
    }

    void addUser(string user, string email){
        users.push_back(user);
        email_to_user[email] = users.size() - 1;
    }

    void unite(string word1, string word2){
        if (!parent.count(word1)){
            parent[word1] = word1;
        }

        if (!parent.count(word2)){
            parent[word2] = word2;
        }

        string parent1 = find(word1);
        string parent2 = find(word2);
        parent[parent2] = parent1;
    }

    vector<vector<string>> getAccounts(){
        vector<vector<string>> ans;
        map<int, vector<string>> temp;

        for (auto& [k, v]: parent){
            int usrIdx = email_to_user[find(v)];
            if (!temp.count(usrIdx)){
                temp[usrIdx].push_back(users[usrIdx]);
            }

            temp[usrIdx].push_back(k);
        }

        for (auto&[k, v]: temp){
            ans.push_back(v);
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        for (auto account: accounts){
            int n = account.size() - 1;
            dsu.addUser(account[0], account[1]);
            dsu.unite(account[1], account[1]);
            for (int i = 1; i <= n - 1; i++){
                dsu.unite(account[i], account[i+1]);
            }
        }

        return dsu.getAccounts();
    }
};