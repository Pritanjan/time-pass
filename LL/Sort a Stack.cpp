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
