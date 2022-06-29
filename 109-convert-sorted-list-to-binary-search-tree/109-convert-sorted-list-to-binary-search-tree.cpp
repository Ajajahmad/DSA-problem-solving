/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        
        int n = nums.size();
        TreeNode* res =  helper(0,n-1, nums);
        return res;
    }
     TreeNode* helper(int l , int r, vector<int>&nums)
    {
        if(l>r) return NULL;
        int m =ceil((float) (l+r)/2);
        TreeNode *root = new TreeNode(nums[m]);
        root->left = helper(l,m-1,nums);
         root->right = helper(m+1,r,nums);
        return root;
    }
};