#include<bits/stdc++.h>
using namespace std;
int main(){

	// Must known bit manipulation concepts

	// Bitwise operators: Works on bit level 

	eg: 20 & 30 
	20: 00010100  //(For simplicity considering only first 8 bits)
	30: 00011110
	    ---------
	 &: 00010100
	    ---------

	// 6 bitwise operators in c++
	Precedence    Operator    Associativity
    1 			  ~		      Right to left
    2			  <<, >>      Left to Right
	3			  & 		  Left to Right
	4			  ^	 		  Left to Right
	5			  |           Left to Right

	// Bitwise And operator (&) (Both should be 1)
	1 & 1 = 1
	1 & 0 = 0
	0 & 1 = 0  
	0 & 0 = 0  

	// Bitwise OR operator (|)  (At least One should be 1)
	1 | 1 = 1 
	1 | 0 = 1 
	0 | 1 = 1  
	0 | 0 = 0 

	// Bitwise XOR Operator (^) (Only one should be 1)
	1 ^ 1 = 0 
	1 ^ 0 = 1 
	0 ^ 1 = 1  
	0 ^ 0 = 0 
	
	// Properties of XOR operator (Very Important) 
	1. A ^ A = 0
    eg:	5 = 101
	    5 = 101
		--------
			000
	    --------
	
	2. A ^ 0 = A
	eg:	5 = 101  //(For simplicity considering only last 3 bits)
	    0 = 000
		--------
			101
	    --------

	3. A ^ B = B ^ A     // Commutative
	4. (A ^ B) ^ C = A ^ (B ^ C)   // Associative
	
	// Not Operator (~)
	Reverses all the bits

	eg: 5: 00000000000000000000000000000101
	   ~5: 11111111111111111111111111111010

	Left most bit is the sign bit: 1 for negative numbers
								   0 for positive numbers   

	Internally -ve numbers store in 2s complement form
	U can google it, if u want to explore more about it

	// Left shift operator (<<)
	Same as multiplication num by 2^k

	eg: 5: 00000000000000000000000000000101
	 5<<1: 00000000000000000000000000001010 = 10 = 5*2  
	 5<<2: 00000000000000000000000000010100 = 20 = 5*(2^2)  
 
	// Right shift operator (>>)
	Same as divide num by 2^k

	eg: 5: 00000000000000000000000000000101
	 5>>1: 00000000000000000000000000000010 = 2 = 5/2
	 5>>2: 00000000000000000000000000000001 = 1 = 5/(2*2)
	
	// Set kth bit of a number
	1. First left shift 1 by (k-1) times
	2. Then use OR operator

	Num |= (1 << (k-1))  // Similar to Num = Num | (1 << (k-1))

	eg: To set 3rd bit in 10
	     	10: 00001010
      1<<(k-1): 00000100
                ---------
			| :	00001110
				---------

	// UnSet kth bit
	1. First left shift 1 by (k-1) times
	2. Reverses all its bits using ~ operator
	3. Then use And operator

	Num = Num & ~(1 << (k-1))


	eg: To UnSet 2nd bit in 10
	       	 10: 00001010
       1<<(2-1): 00000010
    ~(1<<(2-1)): 11111101
                ---------
			 & : 00001000
				---------
	
	// Toggle kth bit
	1. First shift 1 by (k-1) times
	2. Then use XOR operator

	Num ^= 1 << (k-1)  

	eg: To toggle 3rd bit in 10
	     	10: 00001010
      1<<(k-1): 00000100
                ---------
			^ :	00001100
				---------

	// Check if kth bit is set
	
	if(Num & (1 << (k-1)))
		cout << "Set";
	else
		cout << "Not Set"; 

	eg: Check if 4th bit is set in 10
	        10: 00001010
      1<<(k-1): 00001000
                ---------
			& :	00001000 which is true
				---------

	// Check if a given no. is odd

	if(Num & 1)
		cout << "Odd";
	else
		cout << "Even"

	eg: 5: 00000101
		1: 00000001
		    ---------
		&:  00000001 
			---------

	// Check if a given no. is even directly

	if(Num & 1 ^ 1)
		cout << "Even";

	eg: 10: 00001010
		 1: 00000001
		 &: 00000000 
		 1: 00000001
		   ---------
		 ^: 00000001
		   ---------

	// check if a num is power of two   	

	if(!(num & (num-1))
		cout << "YES\n";

	eg: 8: 00001000
	    7: 00000111
	       --------
	    &: 00000000
	       --------
	    Its ! becomes 1 which is true

	eg: 9: 00001001
	    8: 00001000
	       --------
	    &: 00001000
	       --------
	    Its ! becomes 0 which is false 

	// Most important in-built methods

	1. __builtin_popcount(num) // The number of set bits
	2. __builtin_parity(num) // The parity(even or odd) of the number of ones 
	3. __builtin_clz(num) // Number of zeroes at the beginning of a number
	4. __builtin_ctz(num) // Number of zeroes at the end of a number

	eg: 10: 00000000000000000000000000001010
	__builtin_popcount(10): 2
	__builtin_parity(10):   0 
	__builtin_clz(10):     28
	__builtin_ctz(10):      1

	// All these methods are also present for long long type
	// Append ll to all the methods
	1. __builtin_popcountll(num) 
	2. __builtin_parityll(num) 
	3. __builtin_clzll(num) 
	4. __builtin_ctzll(num) 

	// Some very basic Questions for practice
	1. https://leetcode.com/problems/single-number/
	2. https://leetcode.com/problems/power-of-four/
	3. Generate powerset of array using bitwise operators
	4. Search more on GFG, leetcode and codechef for practice
	
}
