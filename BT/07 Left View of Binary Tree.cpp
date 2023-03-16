// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

//Function to return a list containing elements of left view of the binary tree.
void LEFT(Node* root, int level, int& mxLevel, vector<int>& res){
    if(root == nullptr) return ;
    
    if(level > mxLevel) {
        mxLevel = level;
        res.push_back(root -> data);
    }
    
    
    LEFT(root->left, level + 1, mxLevel, res);
    LEFT(root->right, level + 1, mxLevel, res);
}

vector<int> leftView(Node *root){
    vector<int> res;
    int mxLevel = -1;
    LEFT(root, 1, mxLevel, res);
    return res;
}








// 2nd 

void LEFT(Node* root, int level, vector<int>& res){
    if(root == nullptr) return ;
    
    if(level == res.size()) {
        res.push_back(root -> data);
    }
    
    
    LEFT(root->left, level + 1, res);
    LEFT(root->right, level + 1, res);
}

vector<int> leftView(Node *root){
    vector<int> res;
    LEFT(root, 0, res);
    return res;
}

