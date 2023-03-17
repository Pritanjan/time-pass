// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> f(Node* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> L = f(root -> left);
        pair<int, int> R = f(root -> right);
        
        pair<int, int> res;
        
        res.first = root -> data + L.second + R.second;
        res.second = max(L.first, L.second) + max(R.first, R.second);
        
        return res;
    } 
    
    int getMaxSum(Node *root) {
        pair<int, int> res = f(root);
        return max(res.first, res.second);
    }
};



