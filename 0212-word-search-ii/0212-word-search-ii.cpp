struct TrieNode {
    TrieNode* children[26];
    bool isWord = false;
    bool isFound = false;

    TrieNode(){
        memset(children, 0, sizeof(children));
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        this->root = new TrieNode();
    }

    void insert(string word){
        TrieNode* curr = root;
        for (char c: word){
            int idx = c - 'a';
            if (!curr->children[idx]){
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isWord = true;
    }

    bool search(string word){
        TrieNode* curr = root;
        for (char c: word){
            int idx = c - 'a';
            if (!curr->children[idx]){
                return false;
            }

            curr = curr->children[idx];
        }

        if (curr->isFound){
            return false;
        }

        curr->isFound = true;
        return curr->isWord;
    }

    bool prefix(string prefix){
        TrieNode* curr = root;
        for (char c: prefix){
            int idx = c - 'a';
            if (!curr->children[idx]){
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }
};

class Solution {
public:
    void dfs(vector<string>& ans, vector<vector<char>>& board, Trie& dict, int r, int c, string curr_word, vector<vector<bool>>& visited){
        int m = board.size(), n = board[0].size();
        int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        visited[r][c] = true;

        // Early stop
        if (!dict.prefix(curr_word)){
            visited[r][c] = false;
            return;
        }

        if (dict.search(curr_word)){
            ans.push_back(curr_word);
        }

        for (auto& [dr, dc]: dirs){
            int nr = r + dr;
            int nc = c + dc;
            if (nc >= 0 && nc < n && nr >= 0 && nr < m){
                char ch = board[nr][nc];
                if (visited[nr][nc]) continue;

                dfs(ans, board, dict, nr, nc, curr_word + ch, visited);
            }
        }

        visited[r][c] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie dict = Trie();
        for (auto word: words){
            dict.insert(word);
        }

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<string> ans;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                dfs(ans, board, dict, i, j, string{board[i][j]}, visited);
            }
        }

        return ans;
    }
};