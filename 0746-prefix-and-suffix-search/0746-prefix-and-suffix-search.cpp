struct TrieNode{
    TrieNode* children[27];
    int wordIndex = -1;

    TrieNode(){
        memset(children, 0, sizeof(children));
    }
};

struct Trie{
private:
    TrieNode* root;
public:
    Trie(){
        this->root = new TrieNode();
    }

    void insert(string word, int wIdx){
        TrieNode* curr = root;
        curr->wordIndex = wIdx;
        for (char c: word){
            int idx = c - 'a';
            if (!curr->children[idx]){
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
            curr->wordIndex = wIdx;
        }
    }

    int search(string word){
        TrieNode* curr = root;
        for (char c: word){
            int idx = c - 'a';
            if (!curr->children[idx]){
                return -1;
            }
            
            curr = curr->children[idx];
        }

        return curr->wordIndex;
    }
};

class WordFilter {
private:
    Trie dict;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++){
            for (int j = 0; j <= words[i].size(); j++){
                dict.insert(words[i].substr(j) + "{" + words[i], i);
            }
        }
    }
    
    int f(string pref, string suff) {
        return dict.search(suff + "{" + pref);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */