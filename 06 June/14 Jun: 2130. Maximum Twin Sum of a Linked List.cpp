class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        while (slow) {
            ListNode *nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        int ans = 0;
        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};
