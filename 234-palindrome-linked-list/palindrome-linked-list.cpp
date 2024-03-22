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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode *slow = head, *fast = head;
        stack<int> s;

        // Push elements of the first half of the list onto stack
        while (fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the length is odd, skip the middle element
        if (fast)
            slow = slow->next;

        // Compare the second half of the list with the elements popped from the stack
        while (slow) {
            int top = s.top();
            s.pop();

            if (slow->val != top)
                return false;

            slow = slow->next;
        }

        return true;
    }
};
