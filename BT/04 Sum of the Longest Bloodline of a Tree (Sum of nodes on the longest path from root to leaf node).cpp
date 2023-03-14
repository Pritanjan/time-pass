// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// https://www.geeksforgeeks.org/sum-nodes-longest-path-root-leaf-node/

class Solution{
public:

    int maxSum = INT_MIN;
    int maxLen = 0;

    void dfs(Node* node, int level, int sum) {
        if (node == NULL) return;
        
        if (node->left == NULL && node->right == NULL) {
            if (level > maxLen || (level == maxLen && sum + node->data > maxSum)) {
                maxLen = level;
                maxSum = sum + node->data;
            }
            return;
        }
    
        dfs(node->left, level+1, sum+node->data);
        dfs(node->right, level+1, sum+node->data);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        if (root == NULL) return 0;
        dfs(root, 0, 0);
        return maxSum;
    }
};

