#include<bits/stdc++.h>				// Link to the video: https://youtu.be/Sf-P0W_-o8Q
#include<tuple>    				// Defined in tuple header
using namespace std;				
int main(){
	// Used to combine any number of values, which may be of different types
	// eg: 3D point (x co-ord, y co-ord, z co-ord)
	// eg: Weighted Graph edge (vertex1, vertex2, weight)
	
	// syntax: tuple<type1, type2, type3, type4....> tuple1
	// access and modify: get<index>(tuple1)

	tuple<string, int, int> t1; 					        // default constructor
	tuple<string, int, int, int> t2("test2", 1, 2,3);   			// Initialization constructor 	
	tuple<string, int, int> t3(t1);					        //copy constructor
	tuple<int, int, int> t4 = {1, 2, 3};			   			
	tuple<int, int, string> t5 = make_tuple(1, 2, "test5");
	
	-----------------------------
	|Type    |   Default values |
	-----------------------------
	| int	 |        0	    |
	| float	 |       0.0	    |
	| bool	 |      false	    |
	| char	 |      '\0'	    |
	| string |	 ""	    |
	| pointer|       NULL	    |
	-----------------------------

	cout << get<0>(t5) << " " << get<1>(t5) << " " << get<2>(t5); // 1 2 test5
		
	get<0>(t5) = 10;      						// modified the value at first position   
	cout << get<0>(t5);  // 10

	t5 = {10, 20, "test51"};					// assigned a new value
	t5 = make_tuple(100, 200, "test52") ;				// assigned a new value

	// tie(): used to unpack tuple values into separate values
	// 1. Without ignore
	int a, b;
	string c;
	tie(a, b, c) = t5;

	cout << a << " " << b << " " << c;  				// 100 200 test52

	// 2. With ignore 
	tie(a, ignore, c) = t5;
	
	// Some tricks
	int x, y, z;
	tie(x, y, z) = make_tuple(1, 2, 3);    		   // assign
	tie(x, y) = make_tuple(y, x);			   // swap

	// Operators ==, !=, <, >, <=, >= 
	// lexicographically compares the values in the tuple
	// size of tuple and types should be same

	tuple<int, int, int> tup1 = {1, 2, 3};
	tuple<int, int, int> tup2 = {1, 4, 2};

	cout << (tup1 == tup2); 	// 0
	cout << (tup1 != tup2);		// 1		
	cout << (tup1 > tup2);		// 0
	cout << (tup1 < tup2);		// 1 
	cout << (tup1 >= tup2);		// 0
	cout << (tup1 <= tup2);		// 1

	// swap member function (size of tuple and types should be same)

	t1.swap(t3);
}
