// https://www.geeksforgeeks.org/next-smaller-element/
// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> stk;
    stk.push(-1);
    vector<int> res(n);

    for(auto i=n-1; i>=0; i--){
        int cur = arr[i];
        
        while(stk.top() >= cur) stk.pop();

        res[i] = stk.top();
        stk.push(cur);
    }

    return res;
}
