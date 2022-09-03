REVERSE AN ARRAY

APPROACH 1

void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
    int L = m+1;
    int R = arr.size()-1;
    
    while(R > L){
        swap(arr[L],arr[R]);
        R--;
        L++;
    }
//     return arr;
}
//  Time complexity: O(N)
//  Space Complexity: O(1)



APPROACH 2
void reverseArray(vector<int> &arr , int m) {

    int n = arr.size();

    // Declare vector v.
    vector<int> v(n , 0);

    // Declare a varibale p
    int p = 0;
    
    // First fill the v in the same order as the original array upto Mth postion.
    for (int i = 0 ; i <= m ; i++) {
        v[p++] = arr[i];
    }

    // Now fill the v in the reverse order till (m+1)th postion.
    for (int j = n - 1 ; j > m ; j--) {
        v[p++] = arr[j];
    }

    // Now copy back the array v into array ARR.
    for (int i = 0 ; i < n  ; i++) {
        arr[i] = v[i];
    }
}

//  Time complexity: O(N)
//  Space Complexity: O(1)
