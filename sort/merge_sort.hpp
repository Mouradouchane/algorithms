
#pragma once

// this namespace contain classic merge_sort and it's functionalities
namespace sort {

	// private namespace for merger_sort_inplace functions
	namespace {
	
		// O( n ) 
		// merge and sort elements in tow arrays
		// note : this function will return sorted array allocated at the heap
		template<typename T> T* merge_process(
			T* l_array, // start_index  array you want to merge 
			T* r_array, // end_index array you want to merge
			int l_size, // size of start_index  array
			int r_size, // size of end_index array
			bool (* const& compare_function)(T const& a, T const& b) // function used in comparison 
		){
		
			// allocated at the heap new array with size of the tow arrays
			T * new_arr = new T[ sizeof(T) * (l_size + r_size) ];
		
			// variales used in loop
			// l for start_index array
			// r for end_index array
			// n for new array
			int l = 0, r = 0, n = 0;

			for ( ; ; ) {

				// if l & r still in arrays range that mean we can keep going and compare elements
				if (l < l_size && r < r_size) {

					// compare element from start_index array & element from end_index array
					if (compare_function(l_array[l], r_array[r])) {
						// if true insert_process start_index element
						new_arr[n] = l_array[l];
						l += 1;
					}
					else { // otherwise insert_process end_index element
						new_arr[n] = r_array[r];
						r += 1;
					}

					// move to the next empty spot in new_array for next element
					n += 1;
				}
				// l or r is greater than it's ranges mean no more elements to compare soo we break
				else break;

			}


			// if l is still in range that mean there's still elements in start_index array need to get inserted
			if (l < l_size) {
				for ( ; l < l_size; l += 1 , n += 1) {
					new_arr[n] = l_array[l];
				}
			}
			// if r is still in range that mean there's still elements in end_index array need to get inserted
			if (r < r_size) {
				for ( ; r < r_size; r += 1 , n += 1) {
					new_arr[n] = r_array[r];
				}
			}

			// at this point no need to the old start_index & end_index arrays
			// soo delete them & return new sorted array
			delete[] l_array;
			delete[] r_array;

			// last step return new_array mergerd and sorted :)
			return new_arr;
		}


	} // end of private namespace


	// O( n log n )
	// note : this function will return a new sorted array allocated at the heap
	template<typename T> T* merge_sort(
		T* arr   , // target array
		int   left  , // beginning of range you want to sort  
		int   right , // end of range you want to sort  
		bool (* const& compare_function)( T const& a, T const& b ) // function we used to compare elements
	) {

		// if target range greated than 2
		if ((right - left + 1) > 1) {

			// calc index of mid element
			int mid = (right + left) / 2;

			// recursive process from "start_index --> mid" and "mid+1 --> end_index"
			T* l_arr = merge_sort<T>(arr, left, mid, compare_function);
			T* r_arr = merge_sort<T>(arr, mid + 1, right, compare_function);

			// after split done using recursive now it's the time to preforme sorting/merging 
			return merge_process<T>(l_arr, r_arr, (mid - left + 1) , (right - mid) , compare_function);

		}
		else {
			T* element = new T[sizeof(T)];
			element[0] = arr[left];
			return element;
		}
	}

} // end of namespace sort