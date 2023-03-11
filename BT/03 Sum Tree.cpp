// https://practice.geeksforgeeks.org/problems/sum-tree/1

class Solution
{
public:
    pair<bool, int> isSum(Node* root){
        if(root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            pair<bool, int> p = make_pair(true, root -> data);
            return p;
        }
        
        pair<bool, int> L = isSum(root -> left);
        pair<bool, int> R = isSum(root -> right);
        
        bool left = L.first;
        bool right = R.first;
        
        bool cond = root -> data == L.second + R.second;
        
        pair<bool, int> res;
        
        if(left && right && cond){
            res.first = true;
            res.second = 2 * root ->data;
            // res.second = root -> data + left -> second + right -> second;
        }
        else{
            res.first = false;
        }
        
        return res;
    }
    
    bool isSumTree(Node* root) {
         return isSum(root).first;
    }
};



