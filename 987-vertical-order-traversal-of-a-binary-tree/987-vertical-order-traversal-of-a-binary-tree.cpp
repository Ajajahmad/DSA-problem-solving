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
    vector<vector<int>> res;
    map<int , map<int,vector<int>> > mp;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0,0);
        for(auto it:mp)
        {
            map<int, vector<int>> mp1 = it.second;
            vector<int> temp;
            for(auto i:mp1)
            {
                vector<int> a = i.second;
                sort(a.begin(), a.end());
                for(int j=0;j<a.size();j++)
                    temp.push_back(a[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
    void solve(TreeNode *root , int cnt, int lv)
    {
        if(!root) return ;
        mp[cnt][lv].push_back(root->val);
        solve(root->left , cnt-1,lv+1);
        solve(root->right , cnt+1,lv+1);
    }
};