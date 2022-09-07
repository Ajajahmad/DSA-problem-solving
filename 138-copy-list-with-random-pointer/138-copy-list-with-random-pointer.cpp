/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node * , int> mp1cnt;  
        // to store index vs node
        Node *temp = head;
        int cnt =0;
        while(temp)
        {
            mp1cnt[temp] = cnt++;
            temp= temp->next;
        }
        cnt = 0;
        Node *newHead = NULL, *newptr;
        temp = head;
        map<Node * ,Node*>mp1; // 
        map<int , Node*> mp2cnt;
        while(temp)
        {
            if(cnt ==0 )
            {
                Node *newtmp = new Node(temp->val);
                newHead = newtmp;
                newptr= newHead;
                mp2cnt[cnt] = newptr;
                cnt++;
            }
            else
            {
                Node *newtmp = new Node(temp->val);
                newptr->next = newtmp;
                newptr= newtmp;
                mp2cnt[cnt] = newptr;
                cnt++;
            }
            
            mp1[temp] = temp->random;
            temp = temp->next;
        }
        
        
        temp= head;
        Node *newtmp = newHead;
        while(temp)
        {
            if(mp1[temp] == NULL)
            {
                newtmp->random = NULL;
            }
            else
            {
                int index = mp1cnt[mp1[temp]];
                newtmp->random = mp2cnt[index];
            }
            temp = temp->next;
            newtmp = newtmp->next;
        }
        return newHead;
        
    }
};