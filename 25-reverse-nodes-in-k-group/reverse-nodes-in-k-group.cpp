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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        int len = 0;
        
        while (head) {
            len++;
            head = head->next;
        }
        
        while (len >= k) {
            curr = prev->next;
            for (int i = 1; i < k; ++i) {
                ListNode* nextNode = curr->next;
                curr->next = nextNode->next;
                nextNode->next = prev->next;
                prev->next = nextNode;
            }
            prev = curr;
            len -= k;
        }
        
        return dummy->next;
    }
};
