/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        queue<Node*>q1;
        vector<vector<int>>answer_final;
        q1.push(root);
        while(!q1.empty()){
            int qsize = q1.size();
            vector<int>answer;
            answer.clear();
            while(qsize>0){
                Node* top_node = q1.front();
                q1.pop();
                answer.push_back(top_node->val);
                for(auto node_val: top_node->children){
                    q1.push(node_val);
                }
                qsize--;
            }
            answer_final.push_back(answer);
        }
        return answer_final;
    }
};