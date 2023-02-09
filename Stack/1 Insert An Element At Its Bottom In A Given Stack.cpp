// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=0

#include <bits/stdc++.h> 

void solve(stack<int> &st, int x){
    // base case
    if(st.empty()){
        st.push(x);
        return ;
    }
    
    int temp = st.top();
    st.pop();
    
    // recursive call
    solve(st, x);
    
    st.push(temp);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}
