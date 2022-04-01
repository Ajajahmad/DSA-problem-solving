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
    int idx=0;
    map<int,int> mp;
    TreeNode *solve(vector<int>& pre, vector<int>& in, int lb , int ub)
    {
        if(lb>ub) return NULL;
        TreeNode *res = new TreeNode(pre[idx++]);
        if(lb == ub) return res;
        int mid = mp[res->val];
        res->left = solve(pre , in ,lb, mid-1);
        res->right = solve(pre ,in ,mid+1, ub);
        return res;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
         idx =0 ;
        mp.clear();
        for(int i=0;i<n;i++) mp[in[i]] = i;
        TreeNode *res = solve(pre , in ,0 ,n-1);
        return res;
    }
};