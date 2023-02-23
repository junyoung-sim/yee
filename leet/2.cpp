/*
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *temp = head;

        int sum = 0, carry = 0;

        while(l1 != NULL || l2 != NULL) {
            sum = carry;
            if(l1 != NULL) sum += l1->val;
            if(l2 != NULL) sum += l2->val;

            temp->val = sum % 10;
            carry = (sum >= 10);

            if( (l1 != NULL && l1->next != NULL) || (l2 != NULL && l2->next != NULL) ) {
                temp->next = new ListNode();
                temp = temp->next;
            }

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }

        if(carry)
            temp->next = new ListNode(carry);

        return head;
    }
};