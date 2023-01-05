
#pragma once

// this namespace contain merge_sort "in place" and it's functionalities
namespace sort {

	// anonymouse namespace for merger_sort_inplace functions
	namespace {

		// O( 1 )
		template<typename T> void swap(T& a, T& b) {

			T temp = a;
			a = b;
			b = temp;

		}

		// O( n )
		template<typename T> void shift_process_inplace(T* arr, int& start_index, int& end_index) {

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

		// O( n )
		// sort elements in place using shifting function
		template<typename T> void sort_process_inplace(
			T* arr, // target array
			int start, // start index
			int mid, // mid index
			int end, // end index
			bool (*&compare_function)(T const& a, T const& b) // to compare elements
		) {

			int i = start; // index of first element
			int j = mid; // index of mid element

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
			T* arr, // target array
			int left, // start index you want to sort
			int right, // end index 
			bool (*&compare_function)(T const& a, T const& b) // function we using to compare elements
		) {

			// while there's more than 2 elements
			if ((right - left + 1) > 2) {

				// calc mid point
				int mid = (left + right) / 2;

				// O( log n )
				// then recursive process from "start_index to mid" & "mid + 1 to end_index"
				split_process_inplace<T>(arr, left, mid, compare_function);
				split_process_inplace<T>(arr, mid + 1, right, compare_function);

				// O( n )
				// preform merging and sorting after split done
				// sort from start_index to end_index "full range"
				sort_process_inplace<T>(arr, left, mid + 1, right, compare_function);

			}
			else {
				// otherwise mean there's 2 or 1 element in range , so no need to split or merge 
				// just preforme direct comparison 

				if ((right - left + 1) == 2 && !compare_function(arr[left], arr[right])) {

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



	} // end of anonymouse namespace 


	// O( n log n )
	template<typename T> void merge_sort_inplace(
		T* arr, // target array as pointer
		int  start_index, // start index in the array
		int  end_index, // end index in the array
		bool (*compare_function)(T const& a, T const& b) // function used to compare elements
	) {

		// split process calls merge/sort process
		split_process_inplace<T>(arr, start_index, end_index, compare_function);

	}


} // end of namespace sort

