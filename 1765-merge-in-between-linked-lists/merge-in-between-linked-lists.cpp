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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy(0);
        dummy.next = list1;
        
        // Find the ath node
        ListNode* prevA = &dummy;
        for (int i = 0; i < a; ++i) {
            prevA = prevA->next;
        }
        
        // Find the bth node
        ListNode* prevB = prevA;
        for (int i = a; i <= b; ++i) {
            prevB = prevB->next;
        }
        
        // Connect list2 to the end of list1
        ListNode* tailList2 = list2;
        while (tailList2->next) {
            tailList2 = tailList2->next;
        }
        
        prevA->next = list2;
        tailList2->next = prevB->next;
        
        // Disconnect the removed nodes
        prevB->next = nullptr;
        
        return dummy.next;
    }
};