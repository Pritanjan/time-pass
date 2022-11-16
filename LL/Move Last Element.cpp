// https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

#include <bits/stdc++.h> 
/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {
    if(!head or !head -> next)
        return head;
    
    LinkedListNode<int>* temp = head;       // pointer to head
    LinkedListNode<int>* ptr = NULL;        // pointer before head
    
    while(temp -> next != NULL){
        ptr = temp;
        temp = temp -> next;
    }
        
    temp -> next = head;
    ptr -> next = NULL; 
    head = temp;    
    
    return head;
}


// Time Complexity: O(N), As we need to traverse the list once.
// Auxiliary Space: O(1), As constant extra space is used.








