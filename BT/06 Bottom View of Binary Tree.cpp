// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
public:
    vector <int> bottomView(Node *root) {
        if(root == NULL) return {};
        
        vector<int> v;
        map<int, int> mp;
        queue<pair<Node*, int>> que;
        que.push({root, 0});
        
        while(!que.empty()){
            Node* temp = que.front().first;
            int hd = que.front().second;
            que.pop();
            
            mp[hd] = temp -> data;
            
            if(temp -> left)  que.push({temp -> left, hd - 1});
            if(temp -> right)  que.push({temp -> right, hd + 1});
        }
        
        for(auto it=mp.begin(); it != mp.end(); it++){
            v.push_back(it -> second);
        }
        return v;
    }
};

