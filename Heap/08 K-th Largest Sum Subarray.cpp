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
