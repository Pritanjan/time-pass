// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// LC 119

class Solution
{
    public:
    void f(Node* root, int level, vector<int>& res){
        if(root == nullptr) return ;
        
        if(level == res.size()) {
            res.push_back(root -> data);
        }
        
        f(root->right, level + 1, res);
        f(root->left, level + 1, res);
    }
    
    vector<int> rightView(Node *root){
        vector<int> res;
        f(root, 0, res);
        return res;
    }

};

