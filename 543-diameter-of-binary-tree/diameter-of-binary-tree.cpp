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
    int max_d=0;
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d=maxDepth(root->left)+maxDepth(root->right);
        max_d=max(max_d,d);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return max_d;
    }
};