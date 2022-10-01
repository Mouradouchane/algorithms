
#pragma once

namespace sort {

	// anonymouse namespace for binary insertion sort functions
	namespace {

		// O( n )
		template<typename T> void shift_process(T* arr, int& start_index, int& end_index) {

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

		// O( log n )
		// binary search process to get position of where we should insert in insertion process
		template<typename T> int bin_search(

			T* arr, // target array as pointer
			T& target, // target you looking for
			int  l, // left index
			int  r, // right index
			bool (* const& comparison_function)(T const& target, T const& mid_element) // to compare wich way shoud we go left or right

		) {
			// calc mid index
			int mid = (l + r) / 2;

			// if left bigger than right that mean target not found
			if (l >= r) {

				return (comparison_function(target, arr[mid])) ? mid : mid + 1;
	
			}

			// if target found
			if (arr[mid] == target) return mid + 1;
			
			// compare to decied which way to go next 'left' or 'right'
			if ( comparison_function(target, arr[mid]) ) {
				// go left
				mid = bin_search<T>(arr, target, l, mid - 1, comparison_function);
			}
			else {
				// go right
				mid = bin_search<T>(arr, target, mid + 1, r, comparison_function);
			}


			return mid;
		}

	} // end of anonymouse namespace

	// O( n ) --> O( n² )
	template<typename type> void binary_insertion_sort(
		type * arr ,
		size_t const& start_index,
		size_t const& end_index,
		bool (* const& compare_function)( type const& target_element , type const& other_element )
	) {


		size_t mark = start_index + 1; // target index that we want to mark it as sorted
		size_t counter = start_index;  // counter index "to compare with" mark index
		int p = -1; // used to get needed index for shift_process

		// loop to the end
		while (mark <= end_index) {

			/*
				if compare_function return true, that's mean we need to search insert position
				for element at mark index , then shift all elements in that range
			*/
			if ( compare_function(arr[mark], arr[counter]) ) {

				// binary search for index where we arr[mark] should be
				p = bin_search<type>(arr, arr[mark] , start_index, (int)(mark-1), compare_function);

				p = (p < 0) ? 0 : p;
				p = (p > mark) ? mark : p;

				// then preforme shift from p to mark index
				shift_process<type>(arr, p, (int&)mark);

				for (int i = start_index; i < end_index; i += 1) {
					std::cout << arr[i] << " , ";
				}
				std::cout << "\n==================================\n";
			}

			// increment counter & mark
			mark += 1;
			counter += 1;
		}


	} // end of binary_insertion_sort algorithm
	
} // end of namespace sort