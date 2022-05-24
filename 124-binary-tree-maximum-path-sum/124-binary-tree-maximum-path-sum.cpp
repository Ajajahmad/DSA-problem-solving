class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        solver( root,ans);
        return res;
    }
    int solver(TreeNode* root , int &ans){
        if(root==0)return 0;
        
        int l = solver(root->left,ans);
        int r = solver(root->right,ans);
        int m = root->val;
        res = max(res, l+r+m);
        int t= max(m+l,m+r);   
        return max(t,0);
    }
};