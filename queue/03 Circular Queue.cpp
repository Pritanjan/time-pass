// https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=0

#include <bits/stdc++.h> 
class CircularQueue{
    int * arr;
    int qfront;
    int rear;
    int size;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front == 0 and rear == size-1) or (rear == (front - 1) % size - 1)){
            // cout << "FULL " ;
            return 0;
        }
        else if(front == -1) // first eleemnnt{
            front = rear = 0;
            // arr[rear] = value;
        }
        else if(rear == size - 1 and front != 0){ 
            rear = 0; // to maintain cyclic nature
            // arr[rear] = value;
        }
        else {
            rear++; // normal flow
            // arr[rear] = value;
        }
        arr[rear] = value;

        return 1;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){
            return -1; // que is empty
        }

        int ans = arr[front] ;
        arr[front] = -1;

        if(front == rear) // single eleemmnt{
            front = rear = - 1
        }
        else if(front== size-1){
            front = 0;  
        }
        else 
            front++;

        return ans;
    }
};


