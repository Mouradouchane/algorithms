
#pragma once


namespace search {

	// linear search algorithm

	// o( n )
	// boolean version
	template<typename T> bool linear_search_b(
		
		T* arr , 
		size_t length , // zero best index
		T const& target 

	) {

		for (size_t i = 0; i <= length; i += 1) {

			if (arr[i] == target) return true;

		}

		return false;

	}

	// o( n )
	// int index version
	template<typename T> int linear_search_i( 
		
		T* arr, 
		size_t length, // zero best index
		T const& target 

	) {
		
		for (size_t i = 0; i <= length; i += 1) {

			if (arr[i] == target) return i;

		}

		return -1;

	}

}