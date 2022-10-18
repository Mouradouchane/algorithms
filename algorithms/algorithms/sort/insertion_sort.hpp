
#pragma once 

namespace sort {

	namespace {

		// O( n )
		// shift all element in array at specific range
		template<typename T> void shift_process(
			T* arr, // target array
			int& start_index, // start of range
			int& end_index    // end   of range
		) {

			// get target element
			T target = arr[end_index];
			arr[end_index] = NULL;

			// preform shift from last - 1 to the start 
			for (int i = end_index - 1; i >= start_index; i -= 1) {

				arr[i + 1] = arr[i];

			}

			// put target element in it's correct position
			arr[start_index] = target;

		}

		// O(1) --> O(n)
		// function to search for corrent index of element in target_index
		template<typename T> int get_index(
			T* arr, // array
			size_t const& start_index, // start index in arr
			size_t const& target_index, // index of target element
			bool (*&compare_function)(T const& target , T const& element) // function to compare elements
		) {

			// index by default will be the start_index
			int index = start_index;

			// loop from target_index to the start_index 
			for (int i = target_index-1; i >= start_index; i -= 1) {

				// search for correct index
				if ( !compare_function(arr[target_index], arr[i]) ) {
					index = i + 1;
					break;
				}

			}

			// return founded index
			return index;
		}


	} // end of private namespace


	// O( N ) --> O( N² )
	// sorting range of elements in array using "insertion_sort"
	template<typename type> void insertion_sort(
		type * arr , // target array 
		size_t const& start , // start of target range
		size_t const& end ,   // end of target range
		bool (*compare_function)(type const& target , type const& other) // function used to compare elements
	) {

		size_t mark = start + 1; // target index that we want to mark it as sorted
		size_t counter = start;  // counter index "to compare with" mark index
		int p = -1; // used to get needed index for shift_process

		// loop to the end
		while (mark < end) {

			/*
				if compare_function return true, that's mean we need to search insert_process position 
				for element at mark index , then shift all elements in that range
			*/
			if ( compare_function(arr[mark], arr[counter])) {

				// search for index for arr[mark]
				p = get_index<type>(arr, start , mark ,compare_function);
				// then preforme shift from p to mark index
				shift_process<type>(arr, p , (int&)mark);

			}

			// increment counter & mark
			mark += 1;
			counter += 1;
		}

	
	} // end of insertion_sort


} // end of namespace sort