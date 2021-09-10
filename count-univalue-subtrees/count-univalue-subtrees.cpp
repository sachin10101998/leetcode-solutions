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
    int count = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        solve(root);
        return count;
        
    }
    int solve(TreeNode* root) {
        if(root==NULL){
            return INT_MAX;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        if(left==INT_MAX&&right==INT_MAX) {
            count++;
            return root->val;
        }
        else if(left==INT_MAX||right==INT_MAX) {
            if(root->val==left||root->val==right) {
                count++;
                return root->val;
            } else{
                return INT_MIN;
            }
        } else {
            if(root->val==left&&root->val==right) {
                count++;
                return root->val;
            } else{
                return INT_MIN;
            }
        }
    }
};