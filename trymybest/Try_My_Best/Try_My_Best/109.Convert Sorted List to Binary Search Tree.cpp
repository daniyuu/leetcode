//class Solution {
//private:
//    TreeNode *sortedListToBST(ListNode *& list, int start, int end){
//        if (start > end) {
//            return nullptr;
//        }
//        
//        int mid = start + (end - start) / 2;
//        
//        TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
//        TreeNode *parent = new TreeNode(list->val);
//        parent->left = leftChild;
//        list = list->next;
//        
//        parent->right = sortedListToBST(list, mid + 1, end);
//        
//        return parent;
//        
//    }
//public:
//    TreeNode* sortedListToBST(ListNode* head) {
//        int len = 0;
//        ListNode *p = head;
//        while (p) {
//            len++;
//            p = p->next;
//        }
//        
//        return sortedListToBST(head, 0, len - 1);
//    }
//};