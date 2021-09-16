

class Solution {
    map<Node*,Node*>m1;
public:
    
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        if(m1.find(head)!=m1.end()){
            return m1[head];
        }
        Node* node = new Node(head->val, NULL, NULL);
        
        m1[head]=node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        
        return node;
        
    }
};

