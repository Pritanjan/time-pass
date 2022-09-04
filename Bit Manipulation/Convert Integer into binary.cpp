// https://practice.geeksforgeeks.org/problems/binary-representation5003/1

// APPROACH 1: Recursive 
   Following is recursive method to print binary representation of ‘NUM’.
   step 1) if NUM > 1
        a) push NUM on stack
        b) recursively call function with 'NUM / 2'
    step 2)
        a) pop NUM from stack, divide it by 2 and print it's remainder.

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



// Approach 2  Recursive using bitwise operator 
Steps to convert decimal number to its binary representation are given below: 

step 1: Check n > 0
step 2: Right shift the number by 1 bit and recursive function call
step 3: Print the bits of number

void bin(unsigned n)
{
    if (n > 1)
        bin(n >> 1);
 
    printf("%d", n & 1);
// }

    

// APPROACH 3

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


// APPROACH 4

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


APPROACH 5 : Using Bitset of C++
We can use the bitset class of C++ to store the binary representation of any number
(positive as well as a negative number). It offers us the flexibility to have the 
number of bits of our desire, like whether we want to have 32-bit binary representation 
of just an 8-bit representation of a number.
    

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 5, m = -5;
	bitset<8> b(n);
	bitset<8> b1(m);
	cout << "Binary of 5:" << b << endl;
	cout << "Binary of -5:" << b1 << endl;
	return 0;
}

Output:
Binary of 5:00000101
Binary of -5:11111011


Method 6: Using Inbuilt library:
  
#include <bits/stdc++.h>
using namespace std;

void binary(int num){
	//converts the number to binary
	//and removes leading zeroes
	cout << bitset<32>(num).to_string().substr(32 - log2(num));
}

// Driver Code
int main(){
	int x = 10;
	binary(x);
	
}

Output:
the binary number is : 1010
    
Time Complexity: O(1)
Auxiliary Space: O(1)
    
    

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
