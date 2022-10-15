
#include <vector>

#pragma once 

namespace sort {

	// anonymouse namespace for tim sort functionalities
	namespace {

		struct run_info {

		public:
			long int start_index = -1; // start index of that run
			long int end_index = -1;   // end index of that run

			// run_case : mean the case of that run
			/* cases
				0 -> there's no information about that range
				1 -> target range is sorted
				2 -> target range is sorted but in reverse order
				3 -> target range is unsorted
			*/
			short run_case = 0;

			// main constructor
			run_info(long int start_index, long int end_index, short run_case) {
				this->start_index = start_index;
				this->end_index = end_index;
				this->run_case = run_case;
			}
			// def constructor
			run_info() {}
		};


		// size of min run
		static const short min_size_of_run = 6;

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
		// for sorting runs_stack
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
				if ( compare_function(arr[mark], arr[counter]) ) {

					// binary search for index where we arr[mark] should be
					p = bin_search<type>(arr, arr[mark], start_index, (int)(mark - 1), compare_function);

					p = (p < start_index) ? start_index : p;
					p = (p > mark) ? mark : p;

					// then preforme shift from p to mark index
					shift_process<type>(arr, p, (int&)mark);

				}

				// increment counter & mark
				mark += 1;
				counter += 1;
			}


		} // end of binary_insertion_sort algorithm


		// the process to merge tow runs_stack
		template<typename t> void merge_process(
			t * arr ,
			run_info &run1 ,
			run_info &run2 , 
			bool (* const& compare_function)( t const& target , t const& other )
		) {

			// size_t shift_size = run2.start_index - run1.start_index;
			t * run_copy = new t[run1.end_index - run1.start_index + 1];

			// make copy of all elements in run1
			for ( long int i = run1.start_index , c = 0 ; i <= run1.end_index ; i += 1 ,c += 1) {
				run_copy[c] = arr[i];
			}
			
			// start compare_process
			long int cp = 0; // first index at "run_copy"
			long int r1 = run1.start_index; // start index at run2
			long int r2 = run2.start_index; // start index at run2

			while ( true ) {

				if ( !compare_function(run_copy[cp], arr[r2]) ) {

					arr[r1] = arr[r2];
					r2 += 1;

				}
				else {

					arr[r1] = run_copy[cp];
					cp += 1;
				}

				r1 += 1;

				if ( r1 > run2.end_index || r2 > run2.end_index) break;

			}

			// if still there's elements in run_copy
			// those elements should moved to lefted part in run
			if (r2 > run2.end_index && cp < (run1.end_index - run1.start_index) ) {

				while (r1 <= run2.end_index) {

					arr[r1] = run_copy[cp];

					r1 += 1;
					cp += 1;
				}

			}

			delete run_copy;
		
		}

	} // end of anonymouse namespace


	// O(n) --> O(n log n)
	// tim sort algorithm with fixed size of each run
	template<typename type> void tim_sort(
		type* arr, // array as pointer
		size_t const& start_index ,
		size_t const& end_index ,
		// function used to compare elements in array
		bool (* const& compare_function)(type const& target_element, type const& other_element)
	) {

		size_t range = end_index - start_index;

		// if range is less than or equal "32" just preform binary_insertion_sort and stop 
		if ( range <= min_size_of_run) {

			binary_insertion_sort<type>(arr, start_index, end_index, compare_function);
			return;

		}
		
		std::vector<run_info> runs_stack;

		// start sorting ranges and put them in stack of runs
		long int r = start_index;
		for ( ; (r + min_size_of_run ) <= end_index; r += min_size_of_run) {

			// save that range in stack 
			runs_stack.push_back( run_info(r, r + min_size_of_run , 0) );
			// sort that range 
			binary_insertion_sort<type>(arr, r, r + min_size_of_run, compare_function);

			std::cout << '\n';
			std::cout << "Binary Insetion Sort :" << r << " - " << r + min_size_of_run << '\n';
			for (long int i = r; i <= r + min_size_of_run; i += 1) std::cout << arr[i] << " ,";
			std::cout << '\n';

			r += 1;
		}

		// if there's a small range in the end of range 
		if (r < end_index) {

			// save it in stack and sort it
			runs_stack.push_back( run_info(r, end_index , 0) );
			binary_insertion_sort<type>(arr, r, end_index , compare_function);

			std::cout << '\n';
			std::cout << "Binary Insetion Sort :" << r << " - " << r + min_size_of_run << '\n';
			for (long int i = r; i <= end_index; i += 1 ) std::cout << arr[i] << " ,";
			std::cout << '\n';
		}

		// after the sorting is done , now it's the time to start merging runs in stack
		r = runs_stack.size() - 2;
		for ( ; r >= 0 ; r -= 1 ) {

			// merge runs
			merge_process(arr, runs_stack[r], runs_stack[r + 1], compare_function);

			// update stack
			runs_stack[r].end_index = runs_stack[r + 1].end_index; 
			// remove last run from stack
			runs_stack.pop_back(); 

			std::cout << '\n';
			std::cout << "Merge Process ::" << runs_stack[r].start_index << " - " << runs_stack[r].end_index << '\n';
			for (long int i = runs_stack[r].start_index ; i <= runs_stack[r].end_index ; i += 1) std::cout << arr[i] << " ,";
			std::cout << '\n';


		}


	} // end of algorithm tim_sort


} // end of namespace sort