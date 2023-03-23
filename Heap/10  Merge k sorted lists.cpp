// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// WRONG

#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
class node{
    public:
        int data;
        int i;
        int j;
        node(int data, int row, int col){
            this -> data = data;
            i = row;
            j = col;
        }
};

class compare{
  public:
    bool operator()(node* a, node* b){
        return a -> data > b -> data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &p) {
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;
    int k = p.size();

    if(k == 0) return NULL;

    // S1 :
    for(int i=0; i<k; i++){
        if(p[i] != NULL) minHeap.push(p[i]);
    }

    while(minHeap.size() > 0){
        Node<int>* top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL) minHeap.push(top -> next);

        if(head == NULL) { // res LL is empty
            head = top;
            tail = top;
        }
        else{ // insert at LL
            tail -> next = top;
            tail  = top;
        }

        return head;
    }
}










