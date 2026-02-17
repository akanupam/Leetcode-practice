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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return max(height(root->left),height(root->right)) +1;
    }
    int diameter(TreeNode* root, int maxi){
        if(root==NULL) return 0;
        maxi = max(maxi, height(root->left) + height(root->right));
        maxi = max(maxi, diameter(root->left,maxi));
        maxi = max(maxi, diameter(root->right, maxi));
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi = 0;
        maxi = diameter(root, maxi);
        return maxi;
    }
};