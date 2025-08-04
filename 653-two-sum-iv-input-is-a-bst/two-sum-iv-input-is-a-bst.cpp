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

class BST{
    // BST(TreeNode* root){
    //     pushAll(root);
    // }

    // bool isNext(){
    //     return !st.empty();
    // }
};
class Solution {
public:
    void inorder(vector<int>& v,TreeNode* root){
        if(root==NULL) return;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        if(root==NULL) return false;
        inorder(v,root);

        int i=0,j=v.size()-1;
        while(i<j){
            int sum=v[i]+v[j];
            if(sum==k) return true;
            else if(sum>k) j--;
            else i++;
        }
        return false;
    }
};