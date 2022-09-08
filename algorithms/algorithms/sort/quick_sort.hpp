
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
		template<typename T> int parition( 
			T* arr , 
			int left , 
			int right , 
			bool (*&compare_function)(T const& a, T const& b)
		) {

			// "pivot"
			int pv = (left + right) / 2;
			int i = left , j = right;

			while ( i <= j ) {


				while (i <= right) {
					if (compare_function(arr[pv], arr[i])) i += 1;
				}

				while (j >= left) {
					if( !compare_function(arr[pv], arr[j]) ) j -= 1;
				}

				if (j < left) {
					T temp = arr[left];
					arr[left] = arr[pv];
					arr[pv] = temp;
			
					return left;
				}
				else {

					T temp = arr[j+1];
					arr[j+1] = arr[pv];
					arr[pv] = temp;

					return j+1;

				}

			}

		}


	}


	// O( n log n )
	template<typename type> void quick_sort( 
		type * arr ,
		int left ,
		int right ,
		bool (*compare_function)(type const& a, type const& b)
	){

		if (left < right) {

			int partiton_index = parition<type>(arr, left, right , compare_function);

			// preforme quick sort recursivlly in each direction
			quick_sort<type>(arr, left, partiton_index - 1 , compare_function);
			quick_sort<type>(arr, partiton_index + 1 , right , compare_function);

		}

	}


} // end of namespace sort