// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// https://github.com/Pritanjan/Leetcode/blob/main/0201%20-%200300/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree.cpp

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        if(root == p or root == q)
            return root;
        
        TreeNode* L = lowestCommonAncestor(root->left,p,q);
        TreeNode* R = lowestCommonAncestor(root->right,p,q);
        
        if(L != NULL and R != NULL)
            return root;
        else if(L == NULL and R != NULL)
            return R;
        else if(L != NULL and R == NULL)
            return L;
        else
            return L;
    }
};


