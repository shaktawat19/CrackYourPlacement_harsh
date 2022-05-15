ListNode* reverseList(ListNode* head) {
        // Recursive:
        if(head == NULL || head->next == NULL)
            return head;    
        
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
        
        
        //Iterative:
//         if(head == NULL || head->next == NULL)
//             return head;
        
//         ListNode *newHead = NULL;
//         ListNode *nxt = NULL;
//         while(head != NULL){
//             nxt = head->next;
//             head->next = newHead;
//             newHead = head;
//             head = nxt;
//         }
//         return newHead;
}