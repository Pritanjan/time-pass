
int x = 10, y = 5;

# APPROACH 1 (USING ARITHMETIC OPETAORS)

      x = x + y;
      y = x - y;
      x = x + y;

      x = x * y;
      y = x / y;
      x = x / y;
  
# APPROACH 2 (USING BITWISE XOR)
        
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;

# APPROACH 3 ( USING 2 POINTER)
  
  #include <bits/stdc++.h>
  using namespace std;
  void swap(int* xp, int* yp)
  {
      *xp = *xp ^ *yp;
      *yp = *xp ^ *yp;
      *xp = *xp ^ *yp;
  }
 
  // Driver code
  int main()
  {
      int x = 10;
      swap(&x, &x);
      cout << "After swap(&x, &x): x = " << x;
      return 0;
  }

    Output
    After swap(&x, &x): x = 0

      
  In order to avoid getting zero

  #include <bits/stdc++.h>
  using namespace std;
  void swap(int* xp, int* yp)
  {
      // Check if the two addresses are same
      if (xp == yp)
          return;
      *xp = *xp + *yp;
      *yp = *xp - *yp;
      *xp = *xp - *yp;
  }
 
  // Driver Code
  int main()
  {
      int x = 10;
      swap(&x, &x);
      cout << "After swap(&x, &x): x = " << x;
     return 0;
   }

    Output
    After swap(&x, &x): x = 10
      
# DRAWBACK OF ABOVE 3 APPROACH :-
1. The multiplication and division-based approach doesn’t work if one of the numbers is 0 
   as the product becomes 0 irrespective of the other number.
2. Both Arithmetic solutions may cause an arithmetic overflow. If x and y are too large, 
   addition and multiplication may go out of the integer range
3. When we use pointers to variable and make a function swap, all the above methods fail
   when both pointers point to the same variable. Let’s take a look at what will happen 
   in this case if both are pointing to the same variable.
   
   // Bitwise XOR based method 
   x = x ^ x;     // x becomes 0 
   x = x ^ x;     // x remains 0 
   x = x ^ x;     // x remains 0
   // Arithmetic based method 
   x = x + x;     // x becomes 2x 
   x = x – x;     // x becomes 0 
   x = x – x;     // x remains 0

# APPROACH 4 ( A MIXTURE OF BITWISE OPERATORS AND ARITHMETIC OPETAORS)
  The idea is the same as discussed in Method 1 but
  uses Bitwise addition and subtraction for swapping

  #include <bits/stdc++.h>
  using namespace std;

  // Function to swap the numbers.
  void swap(int& a, int& b)
  {
	  // same as a = a + b
	  a = (a & b) + (a | b);
	  // same as b = a - b
	  b = a + (~b) + 1;
	  // same as a = a - b
	  a = a + (~b) + 1;
  }

  // Driver Code
  int main()
  {
	  int a = 5, b = 10;
	  // Function Call
	  swap(a, b);
  	cout << "After swapping: a = " << a << ", b = " << b;
  	return 0;
  }

Output
After swapping: a = 10, b = 5

# APPROACH 5 (ONE LINE EXPRESSION)
  We can write only one line to swap two numbers.

  x = x ^ y ^ (y = x);
  x = x + y – (y = x);
  x = (x * y) / (y = x);
  x , y = y, x (In Python)
      
      
      
      
      
  #include <iostream>
  using namespace std;

  int main(){
	  int x = 10, y = 5;
	  x = (x * y) / (y = x);
	  cout << x << " " << y;
	  return 0;
  }

Output
  5 10
  
 
T.C. -> O(1)
S.C. -> O(1)

