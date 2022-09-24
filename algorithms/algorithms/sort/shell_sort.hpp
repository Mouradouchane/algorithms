
#pragma once

namespace sort {

	namespace {

		// O( 1 )
		// just a normal swap function
		template<typename T> void swap(T& a, T& b) {

			T temp = a;
			a = b;
			b = temp;

		}


	} // end_index of anonymous namespace


	// O( less than n²) --> O( n² )
	// sorting a target range in array using "shell_sort" algorithm
	template<typename type> void shell_sort(
		type* arr , 
		size_t const& start_index , 
		size_t const& end_index ,
		bool (*compare_function)(type const& target , type const& other_element)
	) {

		// if range invalid , we need to stop 
		if (start_index >= end_index) return;

		// gap_size it's the first chosen distance between the elements in array
		// it will decrease each time 
		int gap_size = (int)((end_index - start_index) / 2 );

		// if gap_size is 0 , that's mean it's a rare case where there's a only 2 elements in range
		// so the process would be simpler 
		if (gap_size == 0) {

			// comparison , then swap if it need
			if ( !compare_function(arr[start_index], arr[end_index]) ) {

				swap<type>(arr[start_index], arr[end_index]);

			}

			return;
		}


		// index's used in loop it's like "i and j"
		int index_1 , index_2;

		// loop until that gap_size
		while ( gap_size >= 1 ) {
			
			// set values to the counters 
			// index_1 will be always start from start_index 
			// index_2 will always start from gap_size
			index_1 = start_index;  
			index_2 = index_1 + gap_size;

			// loop till the end and check
			while ( index_2 <= (int)end_index ) {

				// if comparison is valid , then just increment index's
				if (compare_function(arr[index_1], arr[index_2])) {

					index_1 += 1;
					index_2 += 1;

				}
				else { // if comparison not valid

					// swap elements
					swap<type>(arr[index_1], arr[index_2]);

					// then go back
					index_2 = index_1;
					index_1 -= gap_size;

					// loop until we find proper position for element at "index_2"
					while ( index_1 >= (int)start_index) {

						// if comparison not valid
						if (!compare_function(arr[index_1], arr[index_2])) {

							// swap elements , then calculate next index
							swap<type>(arr[index_1], arr[index_2]);

							// decrease index's
							index_2 = index_1;
							index_1 -= gap_size;

						}
						// if comparison is valid that mean we need to beak because we find correct spot
						else break;

					} // end of "searching back" loop


					// update index's for next element's 
					index_1 += gap_size + 1;
					index_2 = index_1 + gap_size;

				}


			} // end of "search forward" loop


			// decrease gap_size to be smaller for more comparsion's
			gap_size -= 1;
		

		} // end of "shell sort" loop

	}

} // end_index of namespace sort