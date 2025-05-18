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
    void iot(TreeNode* root,vector<int> &ans){
        if (root==NULL){return ;}
        iot(root->left,ans);
        ans.push_back(root->val);
        iot(root->right,ans);
    }
    void fixem(TreeNode* root, unordered_map<int,TreeNode*>&mp){
        if (root==NULL){return;}
        mp[root->val]=root;
        fixem(root->left,mp);
        fixem(root->right,mp);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        iot(root,ans);
        int a=0,b=0;
        for (int i=0;i<ans.size();i++){cout<<ans[i]<<' ';}
        cout<<endl;
        vector<int>bns=ans;
        sort(ans.begin(),ans.end());
        for (int i=0;i<ans.size();i++){cout<<ans[i]<<' ';}
        if (bns==ans){return;}
        else {
            for (int i=0;i<ans.size();i++){
                if (ans[i]!=bns[i]){
                    a=bns[i];
                    b=ans[i];
                    break;
                }
            }
        }
        unordered_map<int,TreeNode*> mp;
        fixem(root,mp);
        mp[a]->val=b;
        mp[b]->val=a;
    }
};