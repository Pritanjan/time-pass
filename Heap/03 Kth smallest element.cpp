// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int p[], int l, int r, int k) {
        priority_queue<int> pq;
        
        // step 1 
        for(int i=0; i<k; i++) pq.push(p[i]);
        
        // step 2
        for(int i=k; i<=r; i++){
            if(p[i] < pq.top()){
                pq.pop();
                pq.push(p[i]);
            }
        }
        
        int res = pq.top();
        return res;
    }
};



