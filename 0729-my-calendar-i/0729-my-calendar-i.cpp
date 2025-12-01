struct Node {
    bool hasInterval = false;
    Node* left = nullptr;
    Node* right = nullptr;
};

class SegmentTree{
private:
    Node* root = nullptr;
    const int MIN_RANGE = 0;
    const int MAX_RANGE = 1e9;

    void update(Node*& node, int l, int r, int ql, int qr){
        if (!node) node = new Node();
        if (ql <= l && r <= qr){
            node->hasInterval = true;
            return;
        }

        int mid = l + (r - l) / 2;
        if (ql <= mid) update(node->left, l, mid, ql, qr);
        if (qr > mid) update(node->right, mid + 1, r, ql, qr);

        if (node->left && node->left->hasInterval && node->right && node->right->hasInterval){
            node->hasInterval = true;
        }
    }

    bool query(Node* node, int l, int r, int ql, int qr){
        if (!node) return false;
        if (node->hasInterval){
            return true;
        }
        if (l == r) return false;

        bool res = false;
        int mid = l + (r - l) / 2;
        if (ql <= mid) res |= query(node->left, l, mid, ql, qr);
        if (qr > mid) res |= query(node->right, mid + 1, r, ql, qr);

        return res;
    }

public:
    void update(int ql, int qr){
        update(root, MIN_RANGE, MAX_RANGE, ql, qr);
    }

    bool query(int ql, int qr){
        return query(root, MIN_RANGE, MAX_RANGE, ql, qr);
    }
};

class MyCalendar {
private:
    SegmentTree tree;
public:
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        bool conflict = tree.query(startTime, endTime - 1);
        if (!conflict){
           tree.update(startTime, endTime - 1);
        }

        return !conflict;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */