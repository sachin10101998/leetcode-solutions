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
    map<int, vector<TreeNode*>> m1;
    int height(TreeNode* root){
        if(root==NULL){
            
            return 0;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        int currHeight = 1+max(lheight,rheight);
        if(m1.find(currHeight)==m1.end()){
            vector<TreeNode*> temp;
            temp.push_back(root);
            m1[currHeight]=temp;
        } else{
            m1[currHeight].push_back(root);
        }
        return currHeight;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>>result;
        int t = height(root);
        for(auto x: m1){
            vector<int> temp;
            for(auto y: x.second){
                temp.push_back(y->val);
            }
            result.push_back(temp);
        }
        return result;
    }
};