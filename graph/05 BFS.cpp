// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// https://leetcode.com/discuss/interview-question/1408203/2-bfs-for-graphs

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        
        queue<int> que;
        que.push(0);
        
        vector<int> bfs;
        
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            
            bfs.push_back(node);
            
            for(auto it : adj[node]){
                if(!vis[it]) {
                    vis[it] = 1;
                    que.push(it);
                }
            }
        }
        return bfs;
    }
};



// T.C. --> O(N)
// S.C. --> O(N + 2E)




