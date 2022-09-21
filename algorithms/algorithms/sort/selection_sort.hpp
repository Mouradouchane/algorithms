
#pragma once

namespace sort {

	// private namespace 
	namespace {

		// O( 1 )
		// just a normal swap function
		template<typename T> void swap(T& a, T& b) {

			T temp = a;
			a = b;
			b = temp;

		}

	} // end of private namespace

	// O(n²)
	template<typename type> void selection_sort(
		type* arr, // target array
		size_t const& start, // start index of that range you want to sort
		size_t const& end,   // end   index of that range you want to sort
		bool (*compare_function)(type const& target, type const& other_element) // function to compare elements
	) {

		// "counter/captuer" for index of last min element found
		size_t min_index = NULL;

		// O(n)
		// loop over all elements
		for (size_t i = start; i < end; i += 1) {

			// set i as min index by default
			min_index = i;

			// O(n-c) --> O(n)
			// loop from i+1 to the end , and compare all elements in that range with last minimum found
			for (size_t c = i+1; c < end; c += 1) {
				
				// if comparison false that mean we found new minimum element
				if (!compare_function(arr[min_index], arr[c])) {
					min_index = c;
				}

			}

			// swap only if a true minimum element founded
			if(min_index != i) swap<type>(arr[i], arr[min_index]);

		}

	}


} // end of namespace sort