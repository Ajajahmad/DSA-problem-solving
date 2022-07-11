/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         
       vector<int> res;
        if(root==NULL)
            return res;
       queue<TreeNode *> q;
       q.push(root);
       while(q.size()!=0)
       {
           int siz = q.size();
           int count=0;
           while(siz >0)
           {
               TreeNode *z = q.front();
               if(count==0)
                    res.push_back(z->val);
               q.pop();
               
               if(z->right)
                    q.push(z->right);
                if(z->left)
                    q.push(z->left);
                
                siz--;
                count++;
           }
       }
       return res;
       
    
    }
};