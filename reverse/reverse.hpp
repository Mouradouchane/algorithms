

namespace reverse {

	// O(n)
	// reverse elements in specific range
	template<typename type> void reverse(
		type* arr, 
		size_t const& start_index, 
		size_t const& end_index
	) {
		
		type temp = NULL;
		for (size_t i = start_index, c = end_index; i <= c; i += 1, c -= 1) {

			temp = arr[i];
			arr[i] = arr[c];
			arr[c] = temp;

			temp = NULL;
		}

	}

} // end of namespace reverse