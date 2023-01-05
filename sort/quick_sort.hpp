
#pragma once

namespace sort {

	// private namespace for quick sort stuff
	namespace {

		// O( 1 )
		template<typename T> void swap( T& a , T& b ) {

			T temp = a;
			a = b;
			b = temp;

		}

		// O( n )
		// parameters like quick_sort 
		template<typename T> int parition( 
			T* arr , 
			int left , 
			int right , 
			bool (*&compare_function)(T const& target, T const& other_element)
		) {

			// index of "pivot"
			// index not target elements it's self , target will be mid element
			int pv = left;

			// i : for searching over bigger elements from "left" to "right"
			// j : for searching over smaller elements from "right" to "left"
			int i = left + 1 , j = right;

			// swap "mid" element "with" index of "pv"
			swap<T>(arr[left], arr[ (int)((left + right) / 2) ]);

			// sorting process
			while ( !(i > j) ) {

				// from left to right
				// loop using i and search for bigger element than pivot
				while ( !compare_function(arr[pv], arr[i]) ) {
					i += 1;
					if (i >= right) break;
				}

				// from right to left
				// loop using j and search for smaller element than pivot
				while ( compare_function(arr[pv], arr[j]) ) {
					j -= 1;
					if (j <= left) break;
				}

				// swap only if i less than j
				if (i < j) {
					// swap i & j
					swap<T>(arr[i], arr[j]);

				}

			}

			// put pivot in it's correct index
			if (j != left) {
				swap<T>(arr[pv], arr[j]);
				return j;
			}
			// else mean pivot in correct spot wich is left 
			else return left;
			
		}
		// end of parition function

	} // end of private namespace


	// O( n log n )
	template<typename T> void quick_sort( 
		T * arr , // target array you want to sort
		int left ,   // start index
		int right ,  // end index
		bool (*compare_function)(T const& target, T const& other_element) // function we using it to compare elements and preform sorting
	){
		// if left & right in array range & valid
		if (left < right) {

			// O( n )
			// process sort for one target and return "pivot" index
			int partiton_index = parition<T>(arr, left, right , compare_function);

			// O( log n )
			// preforme quick sort recursivlly in each direction depeneding on "pivot" index

			quick_sort<T>(arr, left, partiton_index - 1 , compare_function);   // left to pivot
			quick_sort<T>(arr, partiton_index + 1 , right , compare_function); // right to pivot

		}

	}


} // end of namespace sort