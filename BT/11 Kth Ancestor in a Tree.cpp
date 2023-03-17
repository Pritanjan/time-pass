// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

Node* f(Node* root, int &k, int node){
    if(root == NULL) return NULL;
    
    if(root -> data == node) return root;
    
    Node* L = f(root -> left, k, node);
    Node* R = f(root -> right, k, node);
    
    if(L != NULL && R == NULL) {
        k--;
        if(k <= 0){
            k = INT_MAX;  // to lock res  so tht it wont reach to 0
            return root;
        }
        return L; 
    }
    
    if(L == NULL && R != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return R; 
    }
    
    return NULL;
    // 
}

int kthAncestor(Node *root, int k, int node) {
    Node* res = f(root, k, node);
    if(res == NULL or res -> data == node) return -1;
    else return res ->data;
}



