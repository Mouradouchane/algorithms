
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

	// sorting a target range in array using "shell_sort" algorithm
	template<typename type> void shell_sort(
		type* arr , 
		size_t const& start_index , 
		size_t const& end_index ,
		bool (*compare_function)(type const& target , type const& other_element)
	) {

		// gap_factor it's the first chosen distance between the elements in array
		// it will decrease each time 
		int gap_factor = (int)((end_index - start_index) / 2 );

		int index_1 , index_2;

		while ( gap_factor >= 1 ) {

			index_1 = start_index;
			index_2 = gap_factor;

			while ( index_2 <= end_index ) {

				if (compare_function(arr[index_1], arr[index_2])) {
					index_1 += 1;
					index_2 += 1;
				}
				else {

					swap<type>(arr[index_1], arr[index_2]);

					index_2 = index_1;
					index_1 -= gap_factor;

					while ( index_1 >= start_index ) {

						if (!compare_function(arr[index_1], arr[index_2])) {

							swap<type>(arr[index_1], arr[index_2]);

							index_2 = index_1;
							index_1 -= gap_factor;

						}
						else break;

					}

					index_1 += gap_factor + 1;
					index_2 = index_1 + gap_factor;
				}

			}

			gap_factor -= 1;
		}

	}

} // end_index of namespace sort