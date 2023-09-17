// https://practice.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

// A 1 - TLE 

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int res = 0;
        for(int i=l; i<=r; i++) {
            res ^= i; 
        }
        return res;
    }
};

// Time complexity: O(N)
// Auxiliary Space: O(1)





// A 2

class Solution {
  public:
    int findXOR(int n) {
        int mod = n % 4;
     
        // If n is a multiple of 4
        if(mod == 0) return n;
     
        // If n % 4 gives remainder 1
        else if(mod == 1) return 1;
     
        // If n % 4 gives remainder 2
        else if(mod == 2) return n + 1;
     
        // If n % 4 gives remainder 3
        else if(mod == 3) return 0;
    }
     
    // Function to return the XOR of elements
    // from the range [l, r]
    int findXOR(int l, int r) {
        return (findXOR(l-1) ^ findXOR(r));
    }
};

// Time Complexity: O(1)
// Auxiliary Space: O(1)







// A 3



