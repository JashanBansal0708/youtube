#include<bits/stdc++.h>
using namespace std;
// Link to the Part 1 video: https://youtu.be/Ce1I79JV9LQ
int main(){
	// syntax: vector<type> vec;	 				// dynamic size arrays
	//--------------------------------------
    	// Vector Declaration and Initialization
    	//--------------------------------------
	vector<int> v1;                                  	    	// Empty vector   {}     			// O(1)
	vector<int> v2(10, 5);					      	// vector of size 10 with values 5 		// O(n)
	vector<int> v3(10);   // check table for default values 	// vector of size 10 with default values 0 	// O(n)
	vector<int> v4(v2); 						// Copying a vector 		 		// O(n)

	vector<int> v5 = v2; 						// copies v2 values into v1  			// O(n)
	vector<int> v6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	    	// Declaration + Initialization  		// O(n)


	-----------------------------
	|Type    |   Default values |
	-----------------------------
	| int	 |        0	    |
	| float	 |       0.0	    |
	| bool	 |      false	    |
	| char	 |      '\0'	    |
	| string |	 ""	    |
	| pointer|      NULL	    |
	-----------------------------

	vector<int> v = {1, 2, 3, 4, 5};

	// Traverse a vector: 3 ways 

	for(int i = 0; i < v.size(); i++)	
		cout << v[i] << " ";						

	for(auto x: v)						// auto automatically detect the type of values
		cout << x << " ";

	//--------------------------
	// Random Access Iterator 
	// Increment/decrement iterators using ++/--
	// deferenced with *
	// Compared against each other using ==, !=	
	//--------------------------
	
	1. begin(), cbegin()
	2. end(), cend()
	3. rbegin(), rcbegin()
	4. rend(), rcend()
	
	vector<int>::iterator itr = v.begin(); 			 // Returns iterator to first element
	auto itr = v.begin();					 

	cout << *itr; 			// print 1   		 // Access value using deference operator

	cout << *(itr + index);		// any index	         // O(1) operation bcz iterator is random access

	for(auto itr = v.begin(); itr != v.end(); itr++)
		cout << (*itr) << " ";				 // iterate from beginning to end

	for(auto itr = v.rbegin(); itr != v.rend(); itr++){
		cout << (*itr) << " ";				 // iterate from end to beginning
		*itr = 10;					 // we can update the values 
	}

	// we can't update values using constant iterators
	for(auto itr = v.cbegin(); itr != v.cend(); itr++){
		*itr = 20;				 	 // produce errors
	}

	// Insertion
	v.insert(v.begin(), value); 				 // Insert at head  		 // O(n)
	v.insert(v.begin() + index, value);  			 // Insert at index		 // O(n)
	v.push_back(value);					 // Insert at tail		 // O(1) on average

	// Remove
	v.erase(v.begin());					// Remove head			 // O(n)
	v.erase(v.begin() + index);				// Remove index			 // O(n)
	v.pop_back();						// Remove tail		       	 // O(1)

	// Access
	cout << v.front();					// Access head 			 // O(1)	
	cout << v.at(index) << " " << v[index];			// Access index			 // O(1)
	cout << v.back();					// Access tail			 // O(1)

	int sz = v.size();					// Returns size of vector
	bool isEmpty = v.empty()				// check if a vector is empty or not
	v.clear();						// clear the vector completely
	v1.swap(v2);						// swap the two vectors  // O(1)
	v1.resize(10);						// resize the vector to 10
	v1.capacity();						// capacity of vector

	// emplace() == insert()				// inplace Insert, efficient when we use objects
	// emplace_back() == push_back()			// inplace insert at end

	// Use range for loop to take vector as input and change values 

	int n; cin >> n;

	vector<int> vec(n);
	
	for(auto &x: vec) 
		cin >> x;							

	for(auto &x: vec)
		x = 10;
}

void passByValue(vector<int> vec){
	cout << "Vector is passed by value: O(n)";
} 

void passByReference(vector<int> &vec){
	cout << "Vector is passed by reference: O(1)";	// Efficient
	vec[0] = 10;					// passed vector can be updated
}

void passByReference(const vector<int> &vec){		// little bit faster 
	vec[0] = 10;					// produce errors
}

vector<int> returnVector(){
	int arr[] = {1, 2, 3, 4, 5};
	return arr;					// Not possible for arrays

	vector<int> v = {1, 2, 3, 4, 5};
	return v;					// possible for vectors
							// Underlined vectors are stored in the heap
}
