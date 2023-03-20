// 1 indexing

class Solution{
public:
    void heapify(vector<int> p, int n, int i){
        int larget = i;
        int L = 2*i;
        int R = 2*i + 1;
        
        if(L <= n && p[larget] < p[L]) larget = L;
        if(R <= n && p[larget] < p[R]) larget = R;
        
        if(larget != i){
            swap(p[larget], p[i]);
            heapify(p, n, larget);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // s1 : merge both arrays into one
        vector<int> res;
        res.push_back(-1);
        
        for(auto i : a) res.push_back(i);
        for(auto i : b) res.push_back(i);
        
        // s2 : build heap using merged array
        int p = res.size();
        for(int i=p/2; i>0; i-- ){
            heapify(res, p, i);
        }
        return res;
    }
};






// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

//  o indexing
class Solution{
public:
    void heapify(vector<int> &p, int n, int i){
        int larget = i;
        int L = 2*i + 1;
        int R = 2*i + 2;
        
        if(L < n && p[larget] < p[L]) larget = L;
        if(R < n && p[larget] < p[R]) larget = R;
        
        if(larget != i){
            swap(p[larget], p[i]);
            heapify(p, n, larget);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // s1 : merge both arrays into one
        vector<int> res;
        
        for(auto i : a) res.push_back(i);
        for(auto i : b) res.push_back(i);
        
        // s2 : build heap using merged array
        int p = res.size();
        for(int i=p/2 - 1; i>=0; i-- ){
            heapify(res, p, i);
        }
        return res;
    }
};

