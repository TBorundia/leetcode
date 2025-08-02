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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        TreeNode* a=new TreeNode(val);
        if(!root) return a;
        while(1){
            if(temp->val<val){
                if(temp->right==NULL){
                    temp->right=a;
                    return root;
                }
                temp=temp->right;
            }
            else{
                if(temp->left==NULL){
                    temp->left=a;
                    return root;
                }
                temp=temp->left;
            }
        }
    }
};