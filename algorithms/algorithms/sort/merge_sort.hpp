#include<list>
#pragma once

// this namespace contain merge_sort "in place" and it's functionalities
namespace sort {

	// private namespace for merger_sort_inplace functions
	namespace {

		// O( 1 )
		template<typename T> void swap(T& a, T& b) {

			T temp = a;
			a = b;
			b = temp;

		}


		template<typename T> void shift_process_inplace(T *arr , int &start_index , int &end_index) {

			T temp1 = arr[end_index];
			arr[end_index] = NULL;
		
			for (int i = end_index - 1; i >= start_index; i -= 1) {

				arr[i+1] = arr[i];

			}

			arr[start_index] = temp1;

		}


		template<typename T> void sort_process_inplace(
			T * arr ,
			int l_start ,
			int r_start ,
			int l_size  ,
			int r_size  ,
			bool (*&compare_function)(T const& a, T const& b)
		) {
			
			int i = l_start;
			int j = r_start; 

			while (i < (l_size + r_size)) {

				if (i == j) {
					i += 1;
					continue;
				}

				// if it valid range
				if ( i < j && compare_function(arr[i], arr[j]) ) {

					// if (j < (l_size + r_size - 1) ) j += 1;
					i += 1;

				}
				// if it not
				else {

					if (i > j && compare_function(arr[i], arr[j])) swap<T>(arr[i], arr[j]);
					else {
						shift_process_inplace<T>(arr, i, j);
					}

					i += 1;
					if (j < (l_size + r_size - 1) ) j += 1;

				}

			}
		}


		template<typename T> void split_process_inplace(
			T*  arr   ,
			int left  ,
			int right ,
			bool (*&compare_function)(T const& a, T const& b)
		) {

			if ( (right - left + 1) > 2 ) {

				int mid  = (left + right) / 2;

				split_process_inplace<T>(arr , left , mid , compare_function);
				split_process_inplace<T>(arr , mid+1  , right , compare_function);


				sort_process_inplace<T>(
					arr  , 
					left , mid + 1 ,
					mid - left + 1 , right - mid  , 
					compare_function
				);


			}
			else {

				if ( (right - left + 1) == 2 && !compare_function(arr[left], arr[right]) ) {

						swap<T>(arr[left], arr[right]);

				}

			}

			std::cout << "\n================================\n\n";
			for (int i = left; i <= right; i += 1) {
				std::cout << arr[i] << " , ";
			}
			std::cout << "\n================================\n\n";
		}

		

	} // end of namespace


	// O( n log n ) ==> O( n² log n )
	template<typename type> void merge_sort_inplace( 
		type * arr ,
		int  left  ,
		int  right ,
		bool (*compare_function)( type const& a , type const& b )
	) {

		split_process_inplace<type>(arr, left, right, compare_function);

	}



} // end of namespace 1


// this namespace contain classic merge_sort and it's functionalities
namespace sort {

	// private namespace for merger_sort_inplace functions
	namespace {
	
		// O( n ) 
		// merge and sort elements in tow arrays
		// note : this function will return sorted array allocated at the heap
		template<typename T> T* merge_process(
			T* l_array, // left  array you want to merge 
			T* r_array, // right array you want to merge
			int l_size, // size of left  array
			int r_size, // size of right array
			bool (*&compare_function)(T const& a, T const& b) // function used in comparison 
		){
		
			// allocated at the heap new array with size of the tow arrays
			T * new_arr = new T[ sizeof(T) * (l_size + r_size) ];
		
			// variales used in loop
			// l for left array
			// r for right array
			// n for new array
			int l = 0, r = 0, n = 0;

			for ( ; ; ) {

				// if l & r still in arrays range that mean we can keep going and compare elements
				if (l < l_size && r < r_size) {

					// compare element from left array & element from right array
					if (compare_function(l_array[l], r_array[r])) {
						// if true insert left element
						new_arr[n] = l_array[l];
						l += 1;
					}
					else { // otherwise insert right element
						new_arr[n] = r_array[r];
						r += 1;
					}

					// move to the next empty spot in new_array for next element
					n += 1;
				}
				// l or r is greater than it's ranges mean no more elements to compare soo we break
				else break;

			}


			// if l is still in range that mean there's still elements in left array need to get inserted
			if (l < l_size) {
				for (l; l < l_size; l += 1 , n += 1) {
					new_arr[n] = l_array[l];
				}
			}
			// if r is still in range that mean there's still elements in right array need to get inserted
			if (r < r_size) {
				for (r; r < r_size; r += 1 , n += 1) {
					new_arr[n] = r_array[r];
				}
			}

			// at this point no need to the old left & right arrays
			// soo delete them & return new sorted array
			delete[] l_array;
			delete[] r_array;

			// last step return new_array mergerd and sorted :)
			return new_arr;
		}


	} // end of private namespace


	// O( n log n )
	// note : this function will return a new sorted array allocated at the heap
	template<typename type> type* merge_sort(
		type* arr   , // target array
		int   left  , // beginning of range you want to sort  
		int   right , // end of range you want to sort  
		bool (*compare_function)( type const& a, type const& b ) // function we used to compare elements
	) {

		// if target range greated than 2
		if ((right - left + 1) > 2) {

			// calc index of mid element
			int mid = (right + left) / 2;

			// recursive process from "left --> mid" and "mid+1 --> right"
			type * l_arr = merge_sort<type>(arr, left, mid, compare_function);
			type * r_arr = merge_sort<type>(arr, mid+1, right, compare_function);

			// after split done using recursive now it's the time to preforme sorting/merging 
			return merge_process<type>( l_arr, r_arr , mid - left + 1 , right - mid , compare_function);

		}

		// else mean range contain 2 or 1 element
		// allocate new array at the heap
		type * new_arr = new type[sizeof(type) * (right - left + 1)];

		// if 2 elements preforme direct comparison
		if ((right - left + 1) == 2) {
			if ( compare_function(arr[left], arr[right]) ) {
				new_arr[0] = arr[left];
				new_arr[1] = arr[right];
			}
			else {
				new_arr[0] = arr[right];
				new_arr[1] = arr[left];
			}
		}
		else { // put element directly 
			new_arr[0] = arr[left];
		}

		// return that new array
		return new_arr;
	}

} // end of namespace 2