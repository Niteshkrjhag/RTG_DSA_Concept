// YOu can swap element in linked list as this is most important case while sorting ll in using QuickSort

// Partitions the list taking the first element as the pivot
Node* partition(Node* head, Node* tail) {
  
      // Select the first node as the pivot node
    Node* pivot = head;
  
    // 'pre' and 'curr' are used to shift all 
      // smaller nodes' data to the left side of the pivot node
    Node* pre = head;
    Node* curr = head;

    // Traverse the list until you reach the node after the tail
    while (curr != tail->next) {
        
        if (curr->data < pivot->data) {
            swap(curr->data, pre->next->data);
          
              // Move 'pre' to the next node
            pre = pre->next;
        }
        
          // Move 'curr' to the next node
        curr = curr->next;
    }
    
    swap(pivot->data, pre->data);
    
      // Return 'pre' as the new pivot
    return pre;
}