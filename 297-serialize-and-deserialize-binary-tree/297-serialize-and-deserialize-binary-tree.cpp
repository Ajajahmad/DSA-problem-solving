/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void solve(TreeNode *root , string &str)
    {
        if(!root)
        {
            str+="N,";
            return;
        }
        str += to_string(root->val);
        str+=",";
        solve(root->left , str);
        solve(root->right , str);
        
    }
    string serialize(TreeNode* root) {
        string str="";
        solve(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    int i=0;
    TreeNode* deserialize(string str) {
       
        if(str[0]=='N') return NULL;
        return convert(str);
    }
    TreeNode *convert(string str)
    {
        if(str[i]=='N') 
        {
            i = i+2;
            return NULL;
        }
        
        int value = 0;
        int sign = 1;
        if(str[i]=='-') sign = -1,i++;
        
        while(str[i]!=',')
        {
            int v = (str[i]-'0');
            value = value *10 +v ;
            i++;
        }
        i++;
        TreeNode *root = new TreeNode(value*sign);
        root->left = convert(str );
        root->right = convert(str );
        return root ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));