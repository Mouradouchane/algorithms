
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
	template<typename type> void bubble_sort(
		type* arr, // target array
		size_t const& start, // start index of that range you want to sort
		size_t const& end,   // end   index of that range you want to sort
		bool (*compare_function)(type const& target, type const& other_element) // function to compare elements
	) {

		// O(n)
		for (size_t sorted_range = end; sorted_range > start; sorted_range -= 1) {

			// O(n-c) --> O(n)
			for (size_t c = start + 1; c < sorted_range; c += 1) {
				
				// if element in c is smaller than element in c-1 we should swap them
				if (compare_function(arr[c], arr[c - 1])) {
					swap<type>(arr[c], arr[c - 1]);
				}

			}
			
		}

	}

} // end of namespace sort