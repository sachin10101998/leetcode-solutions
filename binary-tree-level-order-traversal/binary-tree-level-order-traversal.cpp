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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        queue<TreeNode*>q1;
        if(root==NULL){
            return answer;
        }
        q1.push(root);
        while(!q1.empty()){
            int qsize =q1.size();
            vector<int>temp;
            temp.clear();
            while(qsize>0){
                TreeNode* leader = q1.front();
                q1.pop();
                temp.push_back(leader->val);
                if(leader->left!=NULL){
                    q1.push(leader->left);
                }
                if(leader->right!=NULL){
                    q1.push(leader->right);
                }
                qsize--;
                
            }
            answer.push_back(temp);
        }
        return answer;
    }
};