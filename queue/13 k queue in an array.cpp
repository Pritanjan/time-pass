// https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/

#include <iostream>
using namespace std;

class kQueue{
    
    public:
    
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;
        
        kQueue(int n, int k){
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            
            for(int i=0; i<k; i++){
                front[i] = -1;
                rear[i] = -1;
            }
            
            next = new int[k];
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
            
        
            arr  = new int[n];
            freespot = 0;
            
        }
        
          void enqueue(int data, int qn){
              
            //   overflow
            if(freespot == -1){
                cout << "NO Empty space" << endl;
                return ;
            }
            
            // find first free space
            int idx = freespot;
            
            // update freespot
            freespot = next[idx];
            
            // check wheteher 1st element
            if(front[qn - 1] == -1) front[qn - 1] = idx;
            else next[rear[qn - 1]] = idx;
            
            // update reinterpret_cast
            next[idx] = -1;
            
            // update rear
            rear[qn - 1] = idx;
            
            // push element
            arr[idx] = data;
          }
          
          int dequeue(int qn){
            //   underflow
            if(front[qn - 1] == -1){
                cout << "QUEUE underflow "<< endl;
                return -1;
            }
            
            // find idx to pop
            int idx = front[qn - 1];
            
            // move front
            front[qn-1] = next[idx];
            
            // freeslots ko manage kro
            next[idx] = freespot;
            freespot = idx; 
            
            return arr[idx];
          }
};

int main() {
	kQueue q(10, 3); 
	q.enqueue(10,1);
	q.enqueue(15,1);
	q.enqueue(20,2);
	q.enqueue(25,1);
	
	cout << q.dequeue(1) << endl;
	cout << q.dequeue(2) << endl;
	cout << q.dequeue(1) << endl;
	cout << q.dequeue(2) << endl;
	
	return 0;
}




10
20
15
QUEUE underflow 
-1



