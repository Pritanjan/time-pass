// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

#include <iostream>
#include <deque>
using namespace std;

int solve(int *v, int n, int k){
    std::deque<int> mx(k);;
    std::deque<int> mi(k);;
    
    // addition of first k size window
    for(int i=0; i<k; i++){
        while(!mx.empty() && v[mx.back()] <= v[i]) mx.pop_back();
        
        while(!mi.empty() && v[mi.back()] <= v[i]) mi.pop_back();
        
        mx.push_back(i);
        mi.push_back(i);
        
    }
    
    // 
    int res = 0;
    for(int i=k; i<n; i++){
        res += v[mx.front()] + v[mi.front()];
        
        // next windoww
        while(!mx.empty() && i - mx.front() >= k) mx.pop_front();
        while(!mu.empty() && i - mi.front() >= k) mi.pop_front();
        
        // addition
        while(!mx.empty() && v[mx.back()] <= v[i]) mx.pop_back();
        
        while(!mi.empty() && v[mi.back()] <= v[i]) mi.pop_back();
        
        mx.push_back(i);
        mi.push_back(i);
    }
    
    // consider lst window
}

int main() {
	int v[7] = {2,-5, -1, 7, -3, -1, -2};
	
	cout << solve(v, 7) << endl;
	
	return 0;
}
