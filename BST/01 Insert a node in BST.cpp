#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        // constructor
        Node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

void LevelorderTraversal(Node* root){
    queue<Node*> que;
    que.push(root);
    que.push(NULL);
    
    while(!que.empty()){
        Node* temp = que.front();
        que.pop();
        
        if(temp == NULL){
            // traversal completed
            cout << endl;
            if(!que.empty()){
                // que still has some child nodes
                que.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left) que.push(temp -> left);
            if(temp -> right) que.push(temp -> right);
        }
    }
}

Node* insertToBST(Node* &root, int d){
    // base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }
    
    // right subtree
    if(d > root -> data){
        root -> right = insertToBST(root -> right, d);
    }
    
    // left subtree
    if(d < root -> data){
        root -> left = insertToBST(root -> left, d);
    }
    
    return root;
}

void insert(Node* &root){
    int data;
    cin >> data;
    
    while(data != -1){
        insertToBST(root, data);
        cin >> data;
    }
}

int main() {
	
	Node* root = NULL;
	
	cout << "ENTER data for BST " << endl;
	insert(root);
	
	cout << "Print BST " << endl;
	LevelorderTraversal(root);
	
	return 0;
}



// INPUT:
// 10 8 21 7 27 5 4 3  -1


// Output:
// ENTER data for BST 
// Print BST 
// 10 
// 8 21 
// 7 27 
// 5 
// 4 
// 3 
