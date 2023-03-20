#include <iostream>
using namespace std;

class heap {
  public:
    int p[99];
    int n = 0;
    
    heap (){
        p[0] = -1;
        n = 0;
    }
    void insert(int val) {
        n = n + 1; 
        int idx = n;
        p[idx] = val;
        
        while(idx > 1){
            int parent = idx / 2;
            
            if(p[parent] < p[idx]) {
                swap(p[idx], p[parent]);
                idx = parent;
            }
            else return ;
        }
    }
    void print() {
        for(int i=1; i<n; i++){
            cout << p[i] << " ";
        }
        cout << endl;
    }
    
    void deletefromheap(){
        if(n == 0) {
            cout << "empty"; 
            return ;
        }
        
        // s1 : swap first node & last node
        p[1] = p[n];
        
        // s2 : remove last node
        n--;
        
        // s3 take root node to its correct pos
        int i = 1;
        while(i < n){
            int Lidx = 2*i;
            int Ridx = 2*i + 1;
            
            if(Lidx < n && p[i] < p[Lidx]){
                swap(p[i], p[Lidx]);
                i = Lidx;
            }
            else if(Ridx < n && p[i] < p[Ridx]){
                swap(p[i], p[Ridx]);
                i = Ridx;
            }
            else return ;
        }
    }
    
};

void heapify(int p[], int n, int i){
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

void heapsort(int p[], int n){
    // T.C. -> O(n log n)
    int t = n;
    
    while(t > 1){
        // s1 : swap
        swap(p[t], p[1]);
        
        // s2 :
        t--;
        
        // s3
        heapify(p, t, 1);
    }
}


int main() {
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();
	
	cout << "delete root node" << endl; 
	h.deletefromheap();
	h.print();
	
	int p[6] = {-1, 53, 54, 55, 52, 50};
	int n = 5;
	for(int i=n/2; i>0; i--){
	    heapify(p, n, i);
	}
	
	cout << "heapify" << endl; 
	for(int i=1; i<=n; i++){
	    cout << p[i] << " ";
	}cout << endl;
	
	heapsort(p, n);
	cout << "heap sort" << endl; 
	for(int i=1; i<=n; i++){
	    cout << p[i] << " ";
	}cout << endl;
	
	
	return 0;
}





// T.C. --> O(log N) for insert delete, heapify




// OUTPUT
// 55 54 53 50 
// delete root node
// 54 52 53 
// heapify
// 55 54 53 52 50 




// WE CAN ALSO USE priority_queue to implement max_hea, min_heap




