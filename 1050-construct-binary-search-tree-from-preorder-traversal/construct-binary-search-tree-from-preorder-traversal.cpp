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
    TreeNode* BST(TreeNode* root,int val){
        if(root==NULL) return new TreeNode(val);
        if(val>root->val) root->right=BST(root->right,val);
        else root->left=BST(root->left,val);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& p) {
        TreeNode* root=NULL;
        for(int i=0;i<p.size();i++){
            root=BST(root,p[i]);
        }
        return root;
    }
};