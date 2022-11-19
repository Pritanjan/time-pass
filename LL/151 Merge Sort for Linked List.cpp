// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

// APPROACH 1
//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        vector<int> v;
        // Node* temp = head;
        Node* temp;
        
        // while(temp -> next != NULL){
         for(temp=head; temp->next != NULL; temp=temp->next){
            v.push_back(temp -> data);
            // temp = temp -> next;
        }
        
        v.push_back(temp -> data);
        
        sort(v.begin(), v.end());
        
        temp = head;
        for(int i=0; i<v.size(); i++){
            temp -> data = v[i];
            temp = temp -> next;
        }
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends









// APPROACH 2


// Doing sorting with using only one recurssion call 

//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* merge(Node* l1, Node* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1 -> data > l2 -> data){
            l2 -> next = merge(l1, l2 -> next);
            return l2;
        }
        else{
            l1 -> next = merge(l1 -> next, l2);
            return l1;
        }
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head == NULL or head -> next == NULL)
            return head;
        Node* slow = head;
        Node* mid = slow -> next;
        slow -> next = NULL;
        
        Node* first = mergeSort(head);
        Node* second = mergeSort(mid);
        
        return merge(first, second);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends








