
#pragma once

// this namespace contain merge_sort "in place" and it's functionalities
namespace sort {

	// private namespace for merger_sort_inplace functions
	namespace {

		// O( 1 )
		template<typename T> void swap(T& a, T& b) {

			T temp = a;
			a = b;
			b = temp;

		}

		// O( n )
		template<typename T> void shift_process_inplace(T *arr , int &start_index , int &end_index) {

			// get target element
			T target = arr[end_index];
			arr[end_index] = NULL;
		
			// preform shift from last - 1 to the start 
			for (int i = end_index - 1; i >= start_index; i -= 1) {

				arr[i+1] = arr[i];

			}

			// put target element in it's correct position
			arr[start_index] = target;

		}

		// O( n )
		// sort elements in place using shifting function
		template<typename T> void sort_process_inplace(
			T * arr   , // target array
			int start , // start index
			int mid   , // mid index
			int end   , // end index
			bool (*&compare_function)(T const& a, T const& b) // to compare elements
		) {

			int i = start; // index of first element
			int j = mid ; // index of mid element

			// while i in range
			while (i < end) {

				// i == j no need to for comparison :)
				if (i == j) {
					i += 1;
					continue;
				}

				// if range invalid
				if (i < j && !compare_function(arr[i], arr[j])) {

					// shit from i to j
					shift_process_inplace<T>(arr, i, j);
					// then increment i & j for next range
					i += 1;
					if (j < end) j += 1; // if j at the end don't increment it

				}
				else {

					// if i > j and not a vaild range we need to preform swap
					if (i > j && compare_function(arr[i], arr[j])) swap<T>(arr[i], arr[j]);

					// in that case increment i only 
					i += 1;

				}

			}
		}

		// O( n log n ) 
		// recursive process
		template<typename T> void split_process_inplace(
			T*  arr   , // target array
			int left  , // start index you want to sort
			int right , // end index 
			bool (*&compare_function)(T const& a, T const& b) // function we using to compare elements
		) {

			// while there's more than 2 elements
			if ( (right - left + 1) > 2 ) {
				
				// calc mid point
				int mid  = (left + right) / 2;

				// O( log n )
				// then recursive process from "start_index to mid" & "mid + 1 to end_index"
				split_process_inplace<T>(arr , left , mid , compare_function);
				split_process_inplace<T>(arr , mid+1  , right , compare_function);

				// O( n )
				// preform merging and sorting after split done
				// sort from start_index to end_index "full range"
				sort_process_inplace<T>(arr , left , mid+1 , right , compare_function);

			}
			else { 
				// otherwise mean there's 2 or 1 element in range , so no need to split or merge 
				// just preforme direct comparison 

				if ( (right - left + 1) == 2 && !compare_function(arr[left], arr[right]) ) {

						swap<T>(arr[left], arr[right]);

				}

			}

		}



		// sort process function 1
		/*
		template<typename T> void sort_process_inplace(
			T * arr ,
			int l_start ,
			int r_start ,
			int l_size  ,
			int r_size  ,
			bool (*&compare_function)(T const& a, T const& b)
		) {

			int total_range = l_start + l_size + r_size;
			int i = l_start;
			int j = r_start;

			while ( i < total_range ) {

				if (i == j) {
					i += 1;
					continue;
				}

				// if it valid range
				if ( i < j && !compare_function(arr[i], arr[j]) ) {

					// if (j < (l_size + r_size - 1) ) j += 1;
					shift_process_inplace<T>(arr, i, j);
					i += 1;
					if (j < (l_start + r_size + l_size - 1)) j += 1;

				}
				// if it not
				else {

					if (i > j && compare_function(arr[i], arr[j])) swap<T>(arr[i], arr[j]);

					i += 1;

				}

			}
		}
		*/

		

	} // end of namespace


	// O( n log n )
	template<typename type> void merge_sort_inplace( 
		type * arr , // target array as pointer
		int  start_index , // start index in the array
		int  end_index   , // end index in the array
		bool (*compare_function)( type const& a , type const& b ) // function used to compare elements
	) {

		// split process calls merge/sort process
		split_process_inplace<type>(arr, start_index, end_index, compare_function);

	}


} // end of namespace 1


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
			bool (*&compare_function)(T const& a, T const& b) // function used in comparison 
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
						// if true insert start_index element
						new_arr[n] = l_array[l];
						l += 1;
					}
					else { // otherwise insert end_index element
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
				for (l; l < l_size; l += 1 , n += 1) {
					new_arr[n] = l_array[l];
				}
			}
			// if r is still in range that mean there's still elements in end_index array need to get inserted
			if (r < r_size) {
				for (r; r < r_size; r += 1 , n += 1) {
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
	template<typename type> type* merge_sort(
		type* arr   , // target array
		int   left  , // beginning of range you want to sort  
		int   right , // end of range you want to sort  
		bool (*compare_function)( type const& a, type const& b ) // function we used to compare elements
	) {

		// if target range greated than 2
		if ((right - left + 1) > 2) {

			// calc index of mid element
			int mid = (right + left) / 2;

			// recursive process from "start_index --> mid" and "mid+1 --> end_index"
			type * l_arr = merge_sort<type>(arr, left, mid, compare_function);
			type * r_arr = merge_sort<type>(arr, mid+1, right, compare_function);

			// after split done using recursive now it's the time to preforme sorting/merging 
			return merge_process<type>( l_arr, r_arr , mid - left + 1 , right - mid , compare_function);

		}

		// else mean range contain 2 or 1 element
		// allocate new array at the heap
		type * new_arr = new type[sizeof(type) * (right - left + 1)];

		// if 2 elements preforme direct comparison
		if ((right - left + 1) == 2) {
			if ( compare_function(arr[left], arr[right]) ) {
				new_arr[0] = arr[left];
				new_arr[1] = arr[right];
			}
			else {
				new_arr[0] = arr[right];
				new_arr[1] = arr[left];
			}
		}
		else { // put element directly 
			new_arr[0] = arr[left];
		}

		// return that new array
		return new_arr;
	}

} // end of namespace 2