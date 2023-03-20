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
    
};

int main() {
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();
	
	
	return 0;
}

// T.C. --> O(log N)
