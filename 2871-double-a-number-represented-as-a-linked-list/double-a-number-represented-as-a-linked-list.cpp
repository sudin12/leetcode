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
    ListNode* doubleIt(ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* pointer = res;
        if(head->val > 4) {
            ListNode* temp = new ListNode(1);
            pointer->next = temp;
            pointer = pointer->next;
        }
        while(head) {
            int currentVal = head->val*2;
            if(head->next && head->next->val > 4) currentVal++;
            ListNode* temp = new ListNode(currentVal%10);
            pointer->next = temp;
            pointer = pointer->next;
            head=head->next;
        }
        return res->next;
    }
};