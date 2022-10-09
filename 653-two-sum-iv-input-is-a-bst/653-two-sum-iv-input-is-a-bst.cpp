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
    void inorder(vector<int>&res, TreeNode *root)
    {
        stack<TreeNode *>st;
        while(root!=NULL || !st.empty())
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                root=st.top();
                st.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        
    
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(res,root);
        map<int,int>m;
        for(int i=0;i<res.size();i++)
        {
            if(m.find(k-res[i])!=m.end())
                return true;
            m[res[i]]++;
        }
        return false;
    }
};