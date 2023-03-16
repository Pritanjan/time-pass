// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        if(root == NULL) return {};
        
        vector<int> res;
        
        map<int, int> topNodes;
        
        queue<pair<Node*, int> >que;
        que.push(make_pair(root, 0));
        
        while(!que.empty()) {
            pair<Node*, int> temp = que.front();
            que.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // if one value if present for hd then do nothing
            if(topNodes.find(hd) == topNodes.end()) topNodes[hd] = frontNode -> data;
            
            if(frontNode -> left) que.push(make_pair(frontNode -> left, hd-1));
            if(frontNode -> right) que.push(make_pair(frontNode -> right, hd+1));
        }
        
        for(auto i : topNodes){
            res.push_back(i.second);
        }
        
        return  res;
    }
};


