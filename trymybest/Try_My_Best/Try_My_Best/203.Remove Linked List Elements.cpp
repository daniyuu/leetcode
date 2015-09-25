#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        
        ListNode *cur = head;
        ListNode *next = cur->next;
        
        while (next != NULL) {
            int next_val = next->val;
            if (next_val == val){
                cur->next = next->next;
                delete next;
                next = cur->next;
            }else{
                cur = cur->next;
                next = next->next;
            }
        }
        
        if (head->val == val) {
            cur = head;
            head = head->next;
            delete cur;
        }
        
        return head;
        
    }
};

//
//int main(){
//
//}