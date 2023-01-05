
#pragma once

namespace sort {

	// private namespace for some private function related to heap_sort
	namespace {

		// O( 1 )
		// just a normal swap process 
		template<typename T> void swap(T& a, T& b) {

			T temp = a;
			a = b;
			b = temp;

		}

		// O( 1 ) --> O( log n )
		template<typename T> void heapify(
			T* arr, 
			size_t length,
			int target_index,
			bool (*compare_function)(T const& a, T const& b)
		) {

			// calc left & right children index's
			int left_child  = (target_index * 2) + 1;
			int right_child = (target_index * 2) + 2;

			// if left and right out of array range
			if (left_child > length && right_child > length) return;

			// if left and right inside array range
			if (left_child <= length && right_child <= length) {

				// comapre left with right and take the bigger
				bool l_or_r = compare_function(arr[left_child], arr[right_child]);

				// if left bigger
				if (l_or_r) {

					// compare target with left
					if (compare_function(arr[left_child], arr[target_index])) {

						swap<T>(arr[target_index], arr[left_child]);

						heapify<T>(arr, length, left_child, compare_function);

						return;
					}

				} // if right bigger
				else {

					// compare target with right
					if (compare_function(arr[right_child], arr[target_index])) {

						swap<T>(arr[target_index], arr[right_child]);

						heapify<T>(arr, length, right_child, compare_function);

						return;
					}

				}

			}

			// if only left inside array range 
			if (left_child <= length) {

				// compare target with left
				if (compare_function(arr[left_child], arr[target_index])) {

					swap<T>(arr[target_index], arr[left_child]);

					heapify<T>(arr, length, left_child, compare_function);

					return;

				}
			}

			// if only right inside array range 
			if (right_child <= length) {

				// compare target with right
				if (compare_function(arr[right_child], arr[target_index])) {

					swap<T>(arr[target_index], arr[right_child]);


					heapify<T>(arr, length, right_child, compare_function);

					return;

				}

			}
		}


		// O( n log n )
		// sorting process using swap's and adjust
		template<typename T> void sort_process(

			T* arr,
			int length,
			bool (*compare_function)(T const& a, T const& b)

		) {
			
			// O( n )
			for (int i = length; i > 0; i -= 1) {

				// O( 1 )
				// swap root element with last one
				swap<T>(arr[0], arr[i]);

				// O( log n )
				// adjust the get the new root element 
				heapify<T>(arr, i - 1, 0, compare_function);

			}

		}


	}

	// O( n log n )
	// take array of unsorted elements and sorted them using heap technique
	template<typename T> void heap_sort( 

		T* arr , // target array you want to sort using heap_sort
		size_t length , // length of that array "zero best index"
		bool (*compare_function)( T const& a , T const& b ) // function to compare elements 

	) {

		// O( n )
		// heapify all elements in array
		for (int i = length ; i >= 0; i -= 1) {

			heapify<T>(arr, length , i, compare_function);

		}

		// O( n log n )
		sort_process<T>(arr, length , compare_function);
	}


} // end of namespace sort