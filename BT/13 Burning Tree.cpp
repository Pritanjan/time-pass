// https://practice.geeksforgeeks.org/problems/burning-tree/1

// 1. map parent to the child
// 2. find tgt
// 3.check node is visted or not

class Solution {
public:
    // Level order traversal
    Node* createParentMapping(Node* root, int tgt, map<Node*, Node*> &nodeToParent){
        Node* res = NULL;
        queue<Node*> que;
        que.push(root);
        nodeToParent[root] = NULL;
        
        while(!que.empty()){
            Node* front = que.front();
            que.pop();
            
            if(front -> data == tgt) res = front;
            
            if(front -> left) {
                nodeToParent[front -> left] = front;
                que.push(front -> left);
            }
            
            if(front -> right) {
                nodeToParent[front -> right] = front;
                que.push(front -> right);
            }
        }
        return res;
    }
    
    int burn(Node* root, map<Node*, Node*> &nodeToParent){
        map<Node*, bool> visited;
        
        queue<Node*> que;
        que.push(root);
        
        visited[root] = true;
        
        int cnt = 0;
        
        while(!que.empty()){
            
            bool flag = 0; // to check whether node is visited or not if visted then mark as true
            int n = que.size();
            for(int i=0; i<n; i++){
                // process neighouring nodes
                Node* front = que.front();
                que.pop();
                
                if(front -> left && !visited[front -> left]){
                    flag = 1;
                    que.push(front -> left);
                    visited[front -> left] = 1;
                }
                
                if(front -> right && !visited[front -> right]){
                    flag = 1;
                    que.push(front -> right);
                    visited[front -> right] = 1;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    que.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if(flag == 1){
                cnt++;
            }
        }
        return cnt;
    }
    
    int minTime(Node* root, int target) {
        
        map<Node*, Node*> mp; // nodeToParent
        Node* tgt = createParentMapping(root, target, mp);
        
        int res = burn(tgt, mp);
        
        return res;
    }
};


