//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void bin(unsigned n){
        /* step 1 */
        if (n > 1)
            bin(n / 2);
 
        /* step 2 */
        cout << n % 2;
    }

    string getBinaryRep(int N)
    {
        bin(N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
       
        Solution ob;
        string ans = ob.getBinaryRep(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
