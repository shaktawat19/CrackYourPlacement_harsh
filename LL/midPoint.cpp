
Node* midPoint(Node* head){  
    // Brute: take length of LL, divide by 2. Add/subtract 1 to even/odd nodes mid, acc. to requirement (whether 1st middle or 2nd middle) of mid.
    //          traverse to the mid, n return the mid node.
    
    // optimal: Tortoise method.  Time - O(n/2), space O(1) as fast moves twice of slow.
    if(head == NULL)
        return head;
    Node* slow = head;
    Node* fast = head->next; // here for even node, we are taking first middle node as mid.
    //  Node* fast = head;  we could have used this, if we wanted mid as 2nd middle for even nodes.

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}