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
class BSTIterator {
public:
    TreeNode* curr;
    int index=0;
    TreeNode* curr2;
    vector<TreeNode*> ans;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        solve(root->left);
        ans.push_back(root);
        solve(root->right);
    }
    BSTIterator(TreeNode* root) {
        curr==new TreeNode(INT_MIN);
        curr2==new TreeNode(INT_MIN);
        solve(root);
        ans.insert(ans.begin(),curr);
        ans.insert(ans.end(),curr2);
        
    }
    
    int next() {
        index++;
        return ans[index]->val;
    }
    
    bool hasNext() {
        int n = ans.size();
        if(index>=n-2){
            return false;
        } else{
            return true;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */