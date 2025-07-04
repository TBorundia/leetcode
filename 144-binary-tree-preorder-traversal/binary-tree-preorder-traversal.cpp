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
    void preorder(TreeNode* root,vector<int>& v){
        stack <TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        preorder(root,v);
        return v;
    }
};