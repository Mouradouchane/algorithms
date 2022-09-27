
#pragma once

namespace sort {

	// anonymous namespace for counting_sort
	namespace {

		// O( 1 )
		// just a normal swap function
		template<typename T> void swap(T& a, T& b) {

			T temp = a;
			a = b;
			b = temp;

		}

		// O(n)
		// just a simple function to used for getting min , max , range
		void get_vars(
			unsigned int* arr, 
			size_t const& length ,
			size_t &min ,
			size_t &max ,
			size_t &range
		) {

			min = arr[0];
			max = arr[0];

			for (size_t i = 1; i < length; i += 1) {

				if (arr[i] < min) min = arr[i];
				if (arr[i] > max) max = arr[i];

			}

			range = max - min + 1;

		}

	} // end of anonymous name space 


	void counting_sort(
		unsigned int* arr, // target array 
		size_t length // length/size of that array
	) {

		size_t min = 0;   // min value at the arr
		size_t max = 0;   // max value at the arr
		size_t range = 0; // range of element's in that array (max - min)

		// O(n)
		// get min,max,range using get_vars function
		get_vars(arr, length, min, max, range);

		// allocate a new array with range size at heap 
		// this array will used for counting
		unsigned int* count_arr = new unsigned int[range]{ 0 };
		
		
		// O(n)
		// loop over all elements and count them
		for (size_t i = 0; i < length; i += 1) {

			count_arr[arr[i] - min] += 1;

		}

		// O(range)
		// update counted values for proper sorting later
		for (size_t i = 1; i < range; i += 1) {

			// update range using previous range
			count_arr[i] += count_arr[i - 1];

		}


		// now it's the time to make new array and start sort elements
		unsigned int* new_arr = new unsigned int[length];

		// O(n)
		// sort process "here"
		// loop from back to front for "stable sort" concept
		for (int i = length - 1; i >= 0; i -= 1) {

			new_arr[ --count_arr[ arr[i] - min ] ] = arr[i];

		}

		// move element from sorted array to the original array
		for (size_t i = 0; i < length; i += 1) {
			arr[i] = new_arr[i];
		}


		// delete from heap allocated array's 
		delete[] count_arr;
		delete[] new_arr;

	} // end of counting_sort algorithm

} // end of namespace sort