/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	ListNode *tail = NULL;
    	ListNode *cur = head;
    	int cnt = 0 ;

    	while(cur){
    		cnt++;
    		tail = cur;
    		cur = cur->next;
    	}

    	if(!cnt || !k){
    		return head;
    	}

    	k = cnt - k % cnt;
    	cur = head;

    	while(--k){
    		cur = cur->next;
    	}

    	tail->next = head;
    	head = cur->next;
    	cur->next = NULL;

        return head;
    }
};