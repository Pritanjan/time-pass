// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0

#include <bits/stdc++.h> 
class Queue {
    int * arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        // Implement the Constructor
        size = 1000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear) return 1;
        else return 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size) cout << "FULL " << endl;
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear == qfront) return -1;
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == rear) return -1;
        else return arr[qfront];
    }
}; 

// ALL FUN T.C. IS O(1)



