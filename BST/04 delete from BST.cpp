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

Node* minimum(Node* root){
    Node *temp = root;
    
    while(temp -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* maxmimu(Node* root){
    Node* temp = root;
    
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return root;
}

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

Node* deletfromBST(Node* root, int x){
    // base case
    if(root == NULL) return root;
    
    if(root -> data == x){
        // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }
        
        // 1 child  2 case -> left child & right child
        
        // left child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        
        // right child
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        
        // 2 child
        if(root -> left != NULL && root -> right != NULL){
            int mi =  minimum(root -> right) -> data;
            root -> data = mi;
            root -> right = deletfromBST(root -> right, mi);
            return root;
        }
    }
    else if(root -> data > x){
        int mi =  minimum(root -> right) -> data;
        root -> data = mi;
        root -> right = deletfromBST(root -> right, mi);
        // return root;
    }
    else{
        root -> right = deletfromBST(root -> right, x);
        return root;
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
	
	cout << "minimum is" << minimum(root) -> data;
	cout << "maxmimu is" << maxmimu(root) -> data;
	
	
	root = deletfromBST(root, 30);
	
		
	cout << "ENTER data for BST " << endl;
	insert(root);
	
	cout << "Print BST " << endl;
	LevelorderTraversal(root);
	
	cout << "minimum is" << minimum(root) -> data;
	cout << "maxmimu is" << maxmimu(root) -> data;
	
	
	return 0;
}


// 50 20 70 10 30 90 110 -1
// Runtime Errors:
