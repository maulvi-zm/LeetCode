#include <utility>

using namespace std;

struct Tree {
    pair<int, int> val;
    Tree* left;
    Tree* right;
    Tree(pair<int, int> x) : val(x), left(nullptr), right(nullptr) {}
    Tree(pair<int, int> x, Tree* left, Tree* right)
        : val(x), left(left), right(right) {}
};

Tree* findMin(Tree* root) {
    while (root->left)
        root = root->left;

    return root;
}

void insertNode(Tree*& root, pair<int, int> value) {
    if (root == nullptr) {
        root = new Tree(value);
    } else if (root->val.first == value.first) {
        root->val.second = value.second;
    } else if (root->val.first < value.first) {
        insertNode(root->right, value);
    } else {
        insertNode(root->left, value);
    }
}

void deleteNode(Tree*& root, int key) {
    if (root == nullptr)
        return;

    if (root->val.first < key) {
        deleteNode(root->right, key);
    } else if (root->val.first > key) {
        deleteNode(root->left, key);
    } else { // Found
        if (!root->right && !root->left) {
            root = nullptr;
        } else if (!root->right) {
            root = root->left;
        } else if (!root->left) {
            root = root->right;
        } else {
            Tree* min = findMin(root->right);
            root->val = min->val;
            deleteNode(root->right, min->val.first);
        }
    }
}

int getKey(Tree* root, int key) {
    if (root == nullptr)
        return -1;
    if (root->val.first == key)
        return root->val.second;
    else if (root->val.first < key)
        return getKey(root->right, key);
    else
        return getKey(root->left, key);
}

class MyHashMap {
private:
    Tree* map = nullptr;

public:
    MyHashMap() {}

    void put(int key, int value) { insertNode(map, {key, value}); }

    int get(int key) { return getKey(map, key); }

    void remove(int key) { deleteNode(map, key); }
};