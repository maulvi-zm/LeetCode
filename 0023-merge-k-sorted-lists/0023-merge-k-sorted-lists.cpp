/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isEmpty(vector<ListNode*>& lists){
        for (auto head : lists){
            if (head != nullptr) return false;
        }

        return true;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> numbers;

        for (auto it: lists){
            while (it != nullptr){
                numbers.push(it->val);
                it = it->next;
            }
        }

        ListNode* head = new ListNode();
        ListNode* pointer = head;

        while (!numbers.empty()){
            pointer->next = new ListNode(numbers.top());
            numbers.pop();
            pointer = pointer->next;
        }

        return head->next;
    }
};