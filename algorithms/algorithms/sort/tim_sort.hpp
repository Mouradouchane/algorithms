
namespace sort {

	// anonymouse namespace for tim sort functionalities
	namespace {

		// O( n )
		// shifting process used by "binary insertion sort"
		template<typename T> void shift_process(T* arr, int& start_index, int& end_index) {

			// get target element
			T target = arr[end_index];
			arr[end_index] = NULL;

			// preform shift from last - 1 to the start 
			for (int i = end_index - 1; i >= start_index; i -= 1) {

				arr[i + 1] = arr[i];

			}

			// put target element in it's correct position
			arr[start_index] = target;

		}

		// O( log n )
		// binary search process to get position of where we should insert in insertion process
		template<typename T> int bin_search(

			T* arr, // target array as pointer
			T& target, // target you looking for
			int  l, // left index
			int  r, // right index
			bool (* const& comparison_function)(T const& target, T const& mid_element) // to compare wich way shoud we go left or right

		) {
			// calc mid index
			int mid = (l + r) / 2;

			// if left bigger than right that mean target not found
			if (l >= r) {

				return (comparison_function(target, arr[mid])) ? mid : mid + 1;

			}

			// if target found
			if (arr[mid] == target) return mid + 1;

			// compare to decied which way to go next 'left' or 'right'
			if (comparison_function(target, arr[mid])) {
				// go left
				mid = bin_search<T>(arr, target, l, mid - 1, comparison_function);
			}
			else {
				// go right
				mid = bin_search<T>(arr, target, mid + 1, r, comparison_function);
			}


			return mid;
		}

		// O( n ) --> O( n² )
		// for sorting runs
		template<typename type> void binary_insertion_sort(
			type* arr, // target array as pointer
			size_t const& start_index,
			size_t const& end_index,
			// comparison function
			bool (* const& compare_function)(type const& target_element, type const& other_element) 
		) {


			size_t mark = start_index + 1; // target index that we want to mark it as sorted
			size_t counter = start_index;  // counter index "to compare with" mark index
			int p = -1; // used to get needed index for shift_process

			// loop to the end
			while (mark <= end_index) {

				/*
					if compare_function return true, that's mean we need to search insert position
					for element at mark index , then shift all elements in that range
				*/
				if (compare_function(arr[mark], arr[counter])) {

					// binary search for index where we arr[mark] should be
					p = bin_search<type>(arr, arr[mark], start_index, (int)(mark - 1), compare_function);

					p = (p < 0) ? 0 : p;
					p = (p > mark) ? mark : p;

					// then preforme shift from p to mark index
					shift_process<type>(arr, p, (int&)mark);

				}

				// increment counter & mark
				mark += 1;
				counter += 1;
			}


		} // end of binary_insertion_sort algorithm


		template<typename t> void merge_in_place(
			t * arr ,
			size_t &start_index ,
			size_t &mid_index   , // end index of range 1 & start of range 2
			size_t &end_index   ,
			bool (* const& compare_function)( t const& target , t const& other)
		) {

			size_t shift_size = end_index - mid_index;
			t* temp_range = new t[shift_size];




			delete temp_range;
		}

	} // end of anonymouse namespace

	static const short min_size_of_run = 32;


	template<typename type> void tim_sort(
		type* arr, // array as pointer
		size_t const& start_index ,
		size_t const& end_index ,
		// function used to compare elements in array
		bool (* const& compare_function)(type const& target_element, type const& other_element)
	) {

		size_t range = end_index - start_index;

		// if target range is less than or equal to "min_run_size -> 32"
		if ( range <= min_size_of_run) {
			binary_insertion_sort<type>(arr, start_index, end_index, compare_function);
			return;
		}
		
		tim_sort<type>(arr, start_index, (size_t)(range / 2) - 1, compare_function);
		tim_sort<type>(arr, (size_t)(range / 2) , end_index , compare_function);
		

		
	} // end of algorithm tim_sort


} // end of namespace sort