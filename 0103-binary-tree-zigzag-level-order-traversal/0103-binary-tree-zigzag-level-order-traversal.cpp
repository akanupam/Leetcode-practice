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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        int f = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
            TreeNode* first = q.front();
            temp.push_back(first->val);
            if(first->left) q.push(first->left);
            if(first->right) q.push(first->right);
            q.pop();
            }
            if(f%2!=0){
                reverse(temp.begin(),temp.end());
            }
            f++;
            ans.push_back(temp);
        }
        return ans;
    }
};