// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  private:
  bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1;
      queue<pair<int, int>> que;
      que.push({src, -1});
      
      while(!que.empty()) {
          int node = que.front().first;
          int parent = que.front().second;
          que.pop();
          
          for(auto adjNode : adj[node]) {
              if(!vis[adjNode]) {
                  vis[adjNode] = 1;
                  que.push({adjNode, node});
              }
              else if(parent != adjNode) {
                  return true;
              }
          }
      }
      return false;
  }
  
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};
