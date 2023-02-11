// https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include<bits/stdc++.h>
class SpecialStack {
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:

    stack<int> stk;
    int mi = INT_MAX;
        
    void push(int data) {
        // for first element
        if(stk.empty()){
            stk.push(data);
            mi = data;
        }
        else{
            if(data < mi){
                stk.push(2*data - mi);
                mi = data;
            }
            else{
                stk.push(data);
            }
        }
    }

    int pop() {
        if(stk.empty()) return -1;

        int cur = stk.top();
        stk.pop();

        if(cur > mi) return cur;
        else{
            int prevmin = mi;
            int val = 2 * mi - cur;
            mi = val;
            return prevmin;
        }
    }

    int top() {
        if(stk.empty()) return -1;

        int cur = stk.top();

        if(cur < mi) return mi;
        else return cur;
    }

    bool isEmpty() {
        return stk.empty();
    }
 
    int getMin() {
        if(stk.empty()) return -1;
        else return mi;
    }  
};

// APPROACH 1 TAKE 
