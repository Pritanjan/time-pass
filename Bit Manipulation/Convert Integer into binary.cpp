// https://practice.geeksforgeeks.org/problems/binary-representation5003/1

// APPROACH 1
class Solution
{
public:
    void bin(unsigned n){
        if (n > 1)
            bin(n / 2);
        cout << n % 2;
    }

    string getBinaryRep(int N)
    {
        bin(N);
    }
};



// APPROACH 2

class Solution
{
public:
    string getBinaryRep(int N)
    {
        string s = "000000000000000000000000000000";
        
        for(int i=0; i<32; i++){
            if(N % 2 == 1){
                s[i] = '1';
            }
            N = N / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};


// APPROACH 3

class Solution
{
public:
    string getBinaryRep(int N)
    {
        string ans;
        for(int i=29;i>=0;i--){
            int p = (N>>i)&1;
            ans.push_back('0'+p);
        }
        return ans;
    
    }
};








//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
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
