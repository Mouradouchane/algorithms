
#pragma once


namespace search{

	// anonymouse namespace
	namespace {

		// o( log n )
		// binary search process
		template<typename T> void bin_search_process(

			T*   arr , // target array as pointer
			T&   target , // target you looking for
			bool &result , // boolean result "found or not found"
			int  &catch_target_index , // if you want to get index of target if it exists
			int  l , // left  index
			int  r , // right index
			bool (*comparison_function)( T &target , T &mid_element ) // to compare wich way shoud we go left or right

		) {
			// calc mid index
			int mid = (l + r) / 2;

			// if left bigger than right that mean target not found
			if (l > r) {
				result = false;
				catch_target_index = -1;
				return;
			}

			// if target found
			if ( arr[mid] == target) {
				result = true;
				catch_target_index = mid;
				return;
			}

			// compare to decied which way to go next 'left' or 'right'
			if ( comparison_function( target, arr[mid] ) ) {
				// go left
				bin_search_process<T>(arr, target, result , catch_target_index , l, mid-1, comparison_function);
			}
			else {
				// go right
				bin_search_process<T>(arr, target, result , catch_target_index , mid+1, r, comparison_function);
			}

		}

	} // end of anonymouse scope


	// public algorithms


	// log( n )
	// binary_search boolean version
	template<typename T> bool binary_search_b(

		T* arr , // array as pointer 
		size_t const& length , // array length "zero best index"
		T const& target , // target we looking for
		bool (*comparison_function)( T& target, T& mid_element ) // to compare wich way we should go left or right

	) {

		// no need to index here because it's a boolean search operaion
		int skip = -1;
		bool result = false;

		// search for target
		bin_search_process<T>(arr, (T&)target, result , skip , 0, (int)length , comparison_function);

		return result;
	}



	// log( n )
	// binary_search int index version
	template<typename T> int binary_search_i(

		T* arr , // array as pointer 
		size_t const& length , // array length "zero best index"
		T const& target , // target we looking for
		bool (*comparison_function)(T& target, T& mid_element) // to compare wich way we should go left or right

	) {
		// no need to boolean here because it's a index search operaion
		bool skip = false;
		int result = -1;

		// search for target
		bin_search_process<T>(arr, (T&)target, skip , result, 0, (int)length, comparison_function);

		return result;

	}


}

