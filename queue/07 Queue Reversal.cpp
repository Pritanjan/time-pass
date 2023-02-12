// https://practice.geeksforgeeks.org/problems/queue-reversal/1
// https://www.geeksforgeeks.org/reversing-a-queue/


// APPROACH 1 USING STACK
// element ko queue se nikal ko stack me dalo

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    stack<int> stk;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        stk.push(temp);
    }
    
    while(!stk.empty()){
        int temp = stk.top();
        stk.pop();
        q.push(temp);
    }
    return q;
}

// Time Complexity: O(N), 
// Auxiliary Space: O(N)

// APPROACH 2 RECURSION
 
// Function to reverse the queue
void reverseQueue(queue<int>& q)
{
    // base case
    if (q.size() == 0)
        return;
    // storing front(first element) of queue
    int fr = q.front();
 
    // removing front
    q.pop();
 
    // asking recursion to reverse the
    // leftover queue
    reverseQueue(q);
 
    // placing first element
    // at its correct position
    q.push(fr);
}


// Time Complexity: O(N), 
// Auxiliary Space: O(N)



