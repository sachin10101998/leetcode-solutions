class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        if(head->next==NULL && n==1) return NULL; 
        auto cur = head;
        auto l = head;
        int c = 0;
        while(cur->next != NULL){
            c++;
            cur = cur->next;
        }
        cout<<c;
        if(c==n-1){
            cout<<cur->val;
            head = head->next;
            return head;
        }
        for(int i=1;i<c-n+1;i++){
            l = l->next;
        }
        l->next = l->next->next;
        return head;
    }
    
};