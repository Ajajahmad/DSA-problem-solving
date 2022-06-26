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
    void reorderList(ListNode* head) {
        if(!head) return;
        vector<ListNode *> temp;
        ListNode * p =head;
        while(p){
            temp.push_back(p);
            p = p->next;
        }
        int n = temp.size();
        int i=0, j =n-1;
        while(i<j){
            ListNode *p=temp[i] , *q= temp[j];
            p->next = q;
             q->next = temp[i+1];

           i++;
            j--;
        }
        temp[i]->next = NULL;
        
    }
};