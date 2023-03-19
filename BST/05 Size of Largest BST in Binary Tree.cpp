#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// 3rd 
// T.C. --> O(N)

class info {
  public:
    int mx;
    int mi;
    bool isBST;
    int size;
};

info f(TreeNode<int>* root, int&res){
    if(root == NULL) return {INT_MIN, INT_MAX, true, 0};

    info L = f(root -> left,  res);
    info R = f(root -> right, res);

    info cur;
    cur.size = L.size + R.size + 1;
    cur.mx = max(root -> data, R.mx);
    cur.mi = min(root -> data, L.mi);

    if(L.isBST && R.isBST && (root -> data > L.mx && root -> data < R.mi)) cur.isBST = true;
    else cur.isBST = false;

    if(cur.isBST) res = max(res, cur.size);

    return cur;
}

int largestBST(TreeNode<int>* root) {
    int mx = 0;
    info temp = f(root, mx);
    return mx;
}



// 1st
// check wether every node is BST or not
// t.c. -> O(N^2)

// 2nd
// LEFT SUBTREE BST OR NOT
// RIGHT SUBTREE BST OR NOT
// ROOT -> LEFT < ROOT -> DATA < ROOT -> RIGHT






