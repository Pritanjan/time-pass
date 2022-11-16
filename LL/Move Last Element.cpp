// https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
// https://www.codingninjas.com/codestudio/problems/let-last-be-the-first_920455?leftPanelTab=0


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




// Using Next and Tail Pointer To Change Link

// The idea is to traverse the list till the last node using two pointers, one to store the 
// address of the last node and the other to store the address of the second last node. 

// After traversing the list, make the following required link changes

// (1) Make the second last as last ( ‘secLast’ -> next  = NULL).
// (2) Set next to last as head (‘last’ -> next = ‘head’).
// (3) Make last as head ( ‘head’ = last)
 

// Algorithm :
// (1) If ‘head’ is NULL or ‘head’ -> next is NULL, return ‘head’.
// (2) Take a pointer ‘secLast’ initializes it to NULL and a pointer ‘last’ initializes it to
//     ‘head’.
// (3) Run a loop while ‘last’-> next is not NULL
// (4) Make ‘secLast’ = ‘last’.
// (5) Make ‘last’ = ‘last’ -> ‘next’
// (6) Set ‘secLast’ -> next to NULL
// (7) Set ‘last’ -> next to ‘head’
// (8) Make ‘head’ as ‘last’ i.e ‘head’ = ‘last’.
// (9) Return ‘head









