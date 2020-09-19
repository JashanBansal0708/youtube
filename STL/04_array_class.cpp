// Link to the video https://youtu.be/RfoLSaFQ4Ws
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void passCArray(int arr[], int n){

	// cout << sizeof(arr)/sizeof(int);			 // 1
	
	// for(auto &x: arr)       					     // will not work, produce error
	// 	cout << x << endl;
	
	for(int i=0; i<n; i++)
		cout << arr[i] << endl;
}

void passArray1(array<int, 5> arr){				 // size is hard coded
	for(auto &x: arr)							           // value of array passed by value: O(n)	
		cout << x << " ";

	cout << arr.size() << endl;
}

template<size_t s>								 // generic function using template
void passArray2(array<int,s> &arr){	   			 // always try to pass by reference: O(1)
	for(int i=0; i<arr.size(); i++){	
		cout << arr[i] << endl;
	}
}

int main(){
	// Contiguous memory, homogeneous data and fixed size
	// syntax: array<type, constant size> arr; 
	// declaration and intialization 	

	int cArr1[5];							// garbage values   
	array<int, 5> arr1;						// garbage values

	int cArr2[5] = {};						// values: 0 0 0 0 0 
	array<int, 5> arr2 = {};				// values: 0 0 0 0 0 

	int cArr3[5] = {1, 2, 3};				// values: 1 2 3 0 0 
    array<int, 5> arr3 = {1, 2, 3};			// values: 1 2 3 0 0 

	int cArr4[] = {1, 2, 3, 4, 5};			// values: 1 2 3 4 5
	array<int, 5> arr4 = {1, 2, 3, 4, 5};	// values: 1 2 3 4 5   // can't skip the size

	cArr3 = {1, 2, 3, 4, 5};	      		// later we have to assign the complete list
	arr3 = {1, 2, 3, 4, 5};					// otherwise error


	// size must be known at compile time for array class
	// take memory on stack always

	int n; cin >> n;					
	int *cRunTimeArr = new int[n]; 			// not possible for array class
	delete[] cRunTimeArr;					// heap memory not possible 

	// size of array 

	cout << sizeof(cArr1)/sizeof(int) << endl; 
	cout << arr1.size() << endl;

	// for range loop

	for(int x: cArr4) cout << x << " ";     // 1 2 3 4 5 
	
	for(int x: arr4) cout << x << " ";		// 1 2 3 4 5

	// Important 
	// c-style arrays decayed as pointer, but array class not decayed as pointer
	int *cArr5 = cArr4;  					// an array is just an pointer to the first element
						 					// now cArr5 also points the the same location
	cArr5[0] = 10;		 					// it will update the value for cArr4 also

	for(int i=0; i<5; i++) 					
		cout << cArr4[i] << " ";			// 10 2 3 4 5
	cout << endl;

	cout << sizeof(cArr5)/sizeof(int);      // 1

	for(int x: cArr5) cout << x << " ";  	// will produce error bcz cArr5 is a pointer
	
	// array class not decayed as pointer

	array<int, 5> arr5 = arr4; 				// a new copy created for arr5   // O(n)
	
	arr5[0] = 10;							
	
	for(int i=0; i<arr4.size(); i++) 
		cout << arr4[i] << " "; 			// 1 2 3 4 5 
	cout << endl;

	for(int x: arr5) cout << x << " ";		// 10 2 3 4 5

	// passing to function (same as assignment concept)

	passCArray(cArr1, 5);

	passArray1(arr1);

	passArray2(arr1);                       // always try to pass by reference

	// array in-built functionality

	cout << arr5[1]      << endl;  // 2		// when index out of range, garbage value or seg fault
	cout << arr5.at(1)   << endl;  // 2		// when index out of range, throws exception out_of_range
	
	cout << arr5.front() << endl;  // 1		// first element
	cout << arr5.back()  << endl;  // 5		// last element
	cout << arr5.empty() << endl;  // 0		// check array is empty or not

	// swap two arrays
	arr1.swap(arr2);			   			// O(n) 

	// fill() to fill the entire array with array particular value

	arr1.fill(1); 							// O(n) 

	// Iterator: Random Access iterator for array class
	// Pointed to an element of a container and has the ability to iterate over the container.
	// 1. begin(), cbegin()		returns an iterator to the beginning
	// 2. end(), cend()			returns an iterator to the end
	// 3. rbegin(), rcbegin()   returns a reverse iterator to the beginning
	// 4. rend(), rcend() 		returns a reverse iterator to the end

	array<int,5>::iterator itr1 = arr4.begin();
	auto itr2 = arr4.begin();			  	// very useful

	cout << *itr2;       			// 1	// access value using deferencing operator

	for(auto itr = arr4.begin(); itr != arr4.end(); itr++){
		cout << *itr << " ";
	}

	for(auto itr = arr4.rbegin(); itr != arr4.rend(); itr++){
		cout << *itr << " ";				// 5 4 3 2 1
		*itr = 10;							// we can update values here
	}

	// constant iterator can not used to update values
	for(auto itr = arr4.cbegin(); itr != arr4.cend();  itr++)
		*itr = 10;							// will produce errors

	for(auto itr = arr4.rcbegin(); itr != arr4.rcend(); itr++)
		*itr = 10;							// will produce errors

	// All 6 Comparison operators like tuple works on array class also
	// lexicographically compares the values in the array
	// ==, !=, >, <, >=, <=

	return 0;
}

