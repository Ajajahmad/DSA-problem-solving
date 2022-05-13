/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *pre;
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int siz = q.size();
            int count =0 ;
            while(siz--)
            {
                Node *temp  =q.front();
                
                q.pop();
                if(siz==1) temp->next = 0;
                if(count == 0)
                {
                    count++;
                    pre = temp;
                }
                else
                {
                    pre->next = temp;
                    pre = temp;
                }
                if(temp->left ) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};