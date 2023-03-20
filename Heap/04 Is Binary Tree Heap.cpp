// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Solution {
public:
    int count(struct Node* root){
        // T.C. O(N) 
        if(root == NULL) return 0;
        
        return 1 + count(root -> left) + count(root -> right);
    }
    
    
    bool isCBT(struct Node* root, int idx, int cnt) {
        // T.C. O(N) 
        if(root == NULL) return true;
        
        if(idx >= cnt) return 0;
        else {
            bool L = isCBT(root -> left, 2*idx + 1, cnt);
            bool R = isCBT(root -> right, 2*idx + 2, cnt);
            
            return (L && R);
        }
    }
    
    bool ismaxorder(struct Node* root){
        // T.C. O(N) 
        if(root -> left == NULL && root -> right == NULL) return true;
        
        if(root -> right == NULL)  return (root -> data > root -> left -> data); 
        else {
            bool L = ismaxorder(root -> left);
            bool R = ismaxorder(root -> right);
            
            return (L && R && (root -> data > root -> left -> data && root -> data  > root -> right -> data ) );
        }
    }
    
    bool isHeap(struct Node* root) {
        int idx = 0;
        int totalcount = count(root);
        if(isCBT(root, idx, totalcount) && ismaxorder(root))  return true;
        else return false;
    }
};

// T.C. O(N) 



