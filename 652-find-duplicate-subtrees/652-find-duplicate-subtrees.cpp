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
    unordered_map<string, int>m;
vector<TreeNode *>res;
string solve(TreeNode *root)
{
    if(!root) return "";
    string left = solve(root->left);
    string right = solve(root->right);
    string ans = to_string(root->val) + "$" + left + "$" + right;
    if(m[ans]==1)
        res.push_back(root);
    m[ans]++;
    return ans;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         m.clear();
        res.clear();
        solve(root);
        return res;
    }
};