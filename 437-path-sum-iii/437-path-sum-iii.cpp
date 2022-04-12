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
    long long int res=0;
    void solve(TreeNode *root , int k ,vector<int>&path){
        if(!root) return ;
        path.push_back(root->val);
        solve(root->left , k , path);
        solve(root->right , k , path);
        long long int sum =0;
         for(int i=path.size()-1;i>=0;i--)
         {
             sum+=path[i];
             if(sum==k)
             {
                 res++;
             }
         }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root , targetSum , path);
        return  (int)res;
    }
};