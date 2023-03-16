// https://practice.geeksforgeeks.org/problems/k-sum-paths/1

class Solution{
public:
    void f(Node* root, int k, int &cnt, vector<int> &path){
        if(root == NULL) return ;
        
        path.push_back(root -> data);
        
        // left
        f(root -> left, k, cnt, path);
        
        // right
        f(root -> right, k, cnt, path);
        
        // check for k sum
        int sum = 0;
        for(int i=path.size()-1; i>=0; i--){
            sum += path[i];
            
            if(sum == k) cnt++;
        }
        
        path.pop_back();
    }
    
    int sumK(Node *root,int k){
        vector<int> path;
        int cnt = 0;
        f(root, k, cnt, path);
        
        return cnt;
    }
};
