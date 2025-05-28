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
int ans =0;
 int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        int sum = lh + rh;
        ans =  max(ans,sum);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       maxDepth(root);
       return ans;
    }
};