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
void f(TreeNode* node,int level,vector<int>&res){
    if(node==NULL){
        return ;
    }
    if(level==res.size()){
        res.push_back(node->val);
    }
    f(node->right,level+1,res);
    f(node->left,level+1,res);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        f(root,0,res);
        return res;
    }
};