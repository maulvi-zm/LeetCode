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
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            s.push(slow->val);
            slow = slow->next;

            fast = fast->next->next;
        }

        int max_twin = INT_MIN;
        while (slow){
            max_twin = max(max_twin, s.top() + slow->val);
            s.pop();
            slow = slow->next;
        }

        return max_twin;
    }
};