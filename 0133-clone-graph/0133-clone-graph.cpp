/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }

        queue<Node*> q; 
        unordered_map<int, Node*> m;

        Node* root = new Node(node->val);

        q.push(node);
        m.insert({node->val, root});

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();

            for (auto& n: curr->neighbors){
                if (m.find(n->val) == m.end()){
                    Node* newNode = new Node(n->val);
                    q.push(n);
                    m.insert({n->val, newNode});
                }

                (m[curr->val])->neighbors.push_back(m[n->val]);
            }
        }

        return root;
    }
};