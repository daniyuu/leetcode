#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *cur = head, *temp;
        while (cur->next != NULL) {
            if (cur->val == cur-> next->val) {
                temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};


//int main(){
//
//}