// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// BFS

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





// G 12 

// DFS

class Solution {
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, node, vis, adj) == true) {
                    return true;
                }
            }
            // i.e. element other than parent already vis here 
            // it shows there is a cycle in it 
            else if(it != parent) return true;
        }
        return false;
    }
  public:
    // It will work for single component graph
    // bool isCycle(int V, vector<int> adj[]) {
    //     int vis[V] = {0};
    //     return dfs(1, -1, vis, adj);
    // }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};


