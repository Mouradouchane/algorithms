#pragma once

namespace sort {

	// O( n² )
	// linear sort algoritm 
	template<typename T> void linear_sort(

		T* arr , // array as pointer
		size_t const& length , // length of array
		bool (*comparison_function)(T& a , T&b) // function we gonna using it to compare array elements

	) {

		// varaible for performing some swap if we need 
		T temp = NULL;

		// O(n)
		// loop over all for sorting process
		for (size_t i = 0; i < length; i += 1) {

			// O(n)
			for (size_t c = 0; c < length; c += 1) {
				
				// no need to compare the element with it's self
				if (c == i) continue;
				
				// preforme check using comparison function
				// if true we need to swap elements
				if (comparison_function(arr[i], arr[c])) {

					// swap
					temp = arr[i];
					arr[i] = arr[c];
					arr[c] = temp;

					temp = NULL;

				}

			}

		}

	} // end of linear_sort algorithm


} // end of namespace sort