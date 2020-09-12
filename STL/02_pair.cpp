#include<bits/stdc++.h>
#include<utility> // pair defined in utility header
using namespace std;
int main(){
	// Pair: Used to combine two values, which may be different in types
	// eg: 2D point (x coord, y coord)
	// eg: Interval(start time, end time)
	// eg: Graph edge (vertex1, vertex2)

	// syntax: pair<type1, type2> pair1;
	// first value: pair1.first
	// second value: pair1.second

	pair<int, int> p1;           // default contructor 
	pair<int, int> p2(1, 2);     // Initilization contructor 
	pair<int, int> p3(p2);       // copy contructor
	pair<int, string> p4 = make_pair(1, "test");
	pair<int, string> p5 = {1, "test"};

	--------------------------
	|Type    | Default values|
	-------------------------
	| int	   |        0	 		 |
	| float	 |       0.0		 |
	| bool	 |      false		 |
	| char	 |      '\0'	 	 |
	| string |	     ""		 	 |
	--------------------------

	cout << p1.first << " " << p1.second; // 0 0

	p1.first = 1; 
	p1.second = 2;
	cout << p1.first << " " << p2.second; // 1 2
	
	p1 = {1, "test"};
	
	p1 = make_pair(1, 2);

	// Operators ==, !=, <, >, <=, >= 
	pair<int, int> p1 = {1,2};
	pair<int, int> p2 = {1,3};

	cout << (p1 == p2);		// 0
	cout << (p1 != p2);	  	// 1
	cout << (p1  > p2);		// 0
	cout << (p1  < p2);		// 1
	cout << (p1 <= p2);		// 0
	cout << (p1 >= p2);		// 1

	// swap() member function

	p1.swap(p2); // swap the values of both pairs

	// swap() non member function

	swap(p1, p2);
}
