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
        int n=0,i=0;
        ListNode *t,*p;
        t=head;
        p=head;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        int a[n];
        while(p!=NULL){
            a[i++]=p->val;
            p=p->next;
        }
        i=n-1;
        while(head!=0)
        {
            if(a[i--]!=head->val)
                return false;
            head=head->next;
        }
        return true;
    }
};