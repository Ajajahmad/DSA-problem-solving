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
    Node *p;
    void fun(Node *root)
    {
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            int siz=q.size();
            int count=0;
            while(siz-->0)
            {
                Node *temp = q.front();
                q.pop();
               
                if(count==0)
                {
                    p=temp;
                    count++;
                }
                else
                {
                    p->next=temp;
                    p=temp;
                }
                if(siz==1)
                    temp->next=NULL;
                
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
    }
    Node* connect(Node* root) {
        if(!root) return NULL;
        fun(root);
        return root;
    }
};