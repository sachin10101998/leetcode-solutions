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
    vector<int> answer;
    vector<int> getLonelyNodes(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()){
            TreeNode* top = q1.front();
            q1.pop();
            if(top->left==NULL&&top->right==NULL){
                continue;
            }
            if(top->left!=NULL&&top->right==NULL){
                answer.push_back(top->left->val);
                q1.push(top->left);
            }
            if(top->right!=NULL&&top->left==NULL){
                answer.push_back(top->right->val);
                q1.push(top->right);
            }
            if(top->left!=NULL&&top->right!=NULL){
                q1.push(top->left);
                q1.push(top->right);
            }
            
            
        }
        return answer;
        
    }
};