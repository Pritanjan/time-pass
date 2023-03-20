// https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 

void heapify(vector<int> &p, int n, int i){
    int smallest = i;
    int L = 2*i + 1;
    int R = 2*i + 2;
    
    if(L < n && p[smallest] > p[L]) smallest = L;
    if(R < n && p[smallest] > p[R]) smallest = R;
    
    if(smallest != i){
        swap(p[smallest], p[i]);
        heapify(p, n, smallest);
    }
}


vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}
