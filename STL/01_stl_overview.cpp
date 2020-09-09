#include<bits/stdc++.h>
using namespace std;
int main(){
	// Link to the video: https://youtu.be/-ez8BxGdauw
	STL: Standard Template Library or Containers Library
	|
	|-> Generic Container classes like stack, queue, array, list etc
	|-> Iterators: generalized pointers that point at items in containers
	|-> Algorithmic functions like sort, binary_search, reverse etc

	STL container classes divided into 3 categories(based on how data stored)
	|
	|-> A. Sequence Containers: Data structures which can be accessed/stored sequentially.
							  : Data stored may or may not be contiguous
		|-> 1. array: static contiguous array
		|-> 2. vector: dynamic contiguous array
		|->	3. deque: double-ended queue (internal implementation is different, not so common)
		|->	4. forward_list: singly linked list
		|-> 5. list: doubly linked list

		|-> Container Adapters: provide a different interface for sequential containers
			|-> 1. Stack: Adapts deque container to provide stack (LIFO data structure)
			|-> 2. queue: Adapts deque container to provide queue (FIFO data structure)
			|->	3. priority_queue: Adapts vector container to provide priority queue/Heap 			  	
								 : By default max heap, but we can change it to min heap
	
	|-> B. Associative Containers: implement sorted data structures that can be quickly searched in O(logn)
								 : Internally implemented as self-balancing red-black tree	
		|->	1. set: collection of unique sorted keys
		|-> 2. map: collection of key-value pairs, keys are unique and sorted
		|->	3. multiset: collection of sorted keys
		|-> 4. multimap: collection of key-value pairs, sorted by keys
	
	|-> C. Unordered Associative Containers: Unsorted data structures that can be quickly searched 
									 	     in O(1) amortized(on average), O(n) worst-case complexity
										   : Internally implemented as Hashing data structure
		|-> 1. unordered_set: collection of unique keys, hashed by keys
		|-> 2. unordered_map: collection of key-val pairs, hashed by keys and keys are unique
		|->	3. unordered_multiset: collection of keys, hashed by keys
		|-> 4. unordered_multimap: collection of key-val pairs, hashed by keys
		
}
