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
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int siz = q.size();
            res.clear();
            while(siz--)
            {
                TreeNode * temp = q.front();
                q.pop();
                res.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right ) q.push(temp->right);
            }
        }
        int sum =0;
        for(int i=0;i<res.size();i++) sum+= res[i];
        return sum;
    }
};