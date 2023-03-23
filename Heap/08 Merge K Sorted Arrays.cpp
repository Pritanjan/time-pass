// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
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

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    priority_queue<node*, vector<node*>, compare> min_heap;

    // S1 : insert 1st element of all arrays
    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        min_heap.push(temp);

    }

    vector<int> res;

    // S2 : 
    while(min_heap.size() > 0){
        node* temp = min_heap.top();
        res.push_back(temp -> data);
        min_heap.pop();

        int i = temp -> i;
        int j = temp -> j;

        if(j+1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            min_heap.push(next);
        }
    }
    return res; 
}





