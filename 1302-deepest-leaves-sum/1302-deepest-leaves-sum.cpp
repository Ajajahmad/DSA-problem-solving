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
    int deepestLeavesSum(TreeNode* root) {
        int res=0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int siz = q.size();
            res=0;
            while(siz--)
            {
                TreeNode * temp = q.front();
                q.pop();
                res+= temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right ) q.push(temp->right);
            }
        }

        return res;
    }
};