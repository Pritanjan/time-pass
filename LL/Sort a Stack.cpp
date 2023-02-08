// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=0
// https://leetcode.com/discuss/interview-question/algorithms/125398/given-a-stack-sort-it-in-non-decreasing-order

#include <bits/stdc++.h> 
void sortedInsert(stack<int> &stk, int temp){

    // base case 
    if(stk.empty() or !stk.empty() and stk.top() < temp) {
        stk.push(temp);
        return ;
    }

    int p = stk.top();
    stk.pop();

    sortedInsert(stk, temp);

    stk.push(p); 
}



void sortStack(stack<int> &stk) {
	if(stk.empty()) return ;

    int temp = stk.top();
    stk.pop();

    // Recursive call 
    sortStack(stk);

    sortedInsert(stk, temp);
}

// T.C. each element is popped out elements from stack & insert in the other one. which takes O(N) time .
// So for n elemenets it will be O(N^2)

// S.C. O(N)


