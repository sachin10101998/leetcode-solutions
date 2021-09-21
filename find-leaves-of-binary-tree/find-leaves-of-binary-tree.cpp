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
#include <bits/stdc++.h>
class Solution {
public:
    map<int,vector<TreeNode*>>m1;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        int temp = max(lheight,rheight)+1;
        if(m1.find(temp)==m1.end()){
            vector<TreeNode*> temp2;
            temp2.push_back(root);
            m1[temp]=temp2;
        } else{
            vector<TreeNode*> temp2 = m1[temp];
            temp2.push_back(root);
            m1[temp]=temp2;
        }
        return temp;
        
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        int height_of_tree = height(root);
        vector<vector<int>> answer(height_of_tree+1,vector<int>(0));
       
        for(auto x: m1){
            cout<<x.first<<" ";
            vector<int>temp3;
            for(auto j: x.second){
                cout<<j->val<<" ";
                temp3.push_back(j->val);
                
            }
            cout<<endl;
            answer[x.first] = temp3;
            temp3.clear();
        }
        answer.erase(answer.begin());
        return answer;
    }
};