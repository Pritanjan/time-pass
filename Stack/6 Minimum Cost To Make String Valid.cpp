// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0

// cnt the no of opening & closing braces

#include <bits/stdc++.h> 
int findMinimumCost(string s) {
  if(s.size() % 2 != 0) return -1;

  stack<char> stk;

  for(int i=0; i<s.size(); i++){
    char ch = s[i];

    if(ch == '{') stk.push(ch);
    else{
      if(!stk.empty() && stk.top() == '{') stk.pop();
      else stk.push(ch);
    }
  }

  
  int p = 0, l = 0;
  while(!stk.empty()){
    if(stk.top() == '{') p++;
    else l++;
 
    stk.pop();
  }
    
  int res = (p+1)/2 + (l+1)/2;


  return res;
}



