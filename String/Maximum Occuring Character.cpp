//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string s)
    {
        int arr[26] = {0};
        // create an array of count of charracter
        for(int i=0; i<s.size(); i++){
            // lowercase
            int num = 0;
            if(s[i] >= 'a' and s[i] <= 'z'){
                num = s[i] - 'a';
            }
            else{
                // uppercase
                num = s[i] - 'A';
            }
            arr[num]++;
        }
        int maxi = -1;
        int ans  = 0;
        for(int i=0; i<26; i++){
            if(maxi < arr[i]){
                ans = i;
                maxi = arr[i];
            }
        }
        return 'a' + ans;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends
