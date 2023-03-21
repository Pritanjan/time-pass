// https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include "algorithm"
int getKthLargest(vector<int> &arr, int k) {
	vector<int> res;
	int n = arr.size();

	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum += arr[j];
			res.push_back(sum);
		}
	}

	sort(res.begin(), res.end());

	return res[res.size() - k];

}





// T.C. --> O(N^2)

#include <queue>
int getKthLargest(vector<int> &arr, int k) {
	priority_queue<int, vector<int>, greater<int> > pq;
	
	int n = arr.size();
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum += arr[j];
			if(pq.size() < k) pq.push(sum);
			else if(sum > pq.top()){
				pq.pop();
				pq.push(sum);
			}
		}
	}

	

	return pq.top();

}



// T.C. --> O(N)


