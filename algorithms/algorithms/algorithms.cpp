#include <iostream>

/*
#include "sort/hierarchical_sorting.hpp"
#include "sort/heap_sort.hpp"
#include "sort/linear_sort.hpp"
#include "sort/quick_sort.hpp"

#include "search/binary_search.hpp"
#include "search/linear_search.hpp"
*/

#include "sort/merge_sort.hpp"

template<typename T> void print_array(T* arr, size_t const& length);

bool cp_fn( int const& a, int const& b ) {
    return a < b;
}

int main(){

    int arr[20] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };

    print_array<int>(arr, (sizeof(arr) / sizeof(int)));

    sort::merge_sort_inplace<int>(arr, 0, (int)(sizeof(arr) / sizeof(int)) - 1, &cp_fn);

    print_array<int>( arr , (sizeof(arr) / sizeof(int)) );


    return 0;
}



template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}