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
        int n=0;
        ListNode *temp =head;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        if(n<k) return head;
        ListNode *prev= NULL, *curr=head, *next;
        int x= k;
        while(curr && x--)
        {
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(curr)
        {
            head->next = reverseKGroup(curr, k);
        }
        head= prev;
        return head;
    }
};