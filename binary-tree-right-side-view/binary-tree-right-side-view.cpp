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
    vector<vector<int>>trav2;
    vector<vector<int>>trav;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        } else{
            int lheight = height(root->left);
            int rheight = height(root->right);
            return 1 + max(lheight,rheight);
        }
    }
    
    
    vector<int> solve(TreeNode* root, int level, vector<int>&trav2){
        if(root==NULL){
            return trav2;
        }
        else if(level==1){
            trav2.push_back(root->val);
        }
        else{
            solve(root->left, level-1, trav2);
            solve(root->right, level-1, trav2);
        }
        return trav2;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        int height_of_tree = height(root);
        for(int i=1;i<=height_of_tree;i++){
            vector<int> tempo;
            vector<int>temp2 = solve(root, i, tempo);
            ans.push_back(temp2);
        }
        vector<int> anss;
        for(int i=0;i<ans.size();i++){
            vector<int> temppp = ans[i];
            anss.push_back(temppp[temppp.size()-1]);
        }
        return anss;

        
    }
};