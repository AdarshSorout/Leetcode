/**
 * Definition for a binary tree root.
 * struct Treeroot {
 *     int val;
 *     Treeroot *left;
 *     Treeroot *right;
 *     Treeroot() : val(0), left(nullptr), right(nullptr) {}
 *     Treeroot(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treeroot(int x, Treeroot *left, Treeroot *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int counter = 0;
    int result = -1;

    void inorder(TreeNode* root, int k) {
        if (!root || counter >= k) return;

        inorder(root->left, k);

        counter++;
        if (counter == k) {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
