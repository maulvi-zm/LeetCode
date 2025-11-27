struct TrieNode {
    TrieNode* children[26];
    bool isWord = false;

    TrieNode(){
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
    
    bool search(string word) {
        return recurse(root, word, 0);
    }

    bool recurse(TrieNode* node, string word, int pos){
        if (!node) return false;
        if (pos == word.size()) return node->isWord;

        char c = word[pos];
        if (c == '.'){
            for (auto &child: node->children){
                if (child && recurse(child, word, pos + 1)){
                    return true;
                }
            }

            return false;
        } else {
            int idx = c - 'a';
            return recurse(node->children[idx], word, pos + 1);
        }

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */