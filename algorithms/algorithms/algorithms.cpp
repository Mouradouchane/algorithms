#include <iostream>

/*
#include "sort/heap_sort.hpp"
#include "sort/linear_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/merge_sort.hpp"
#include "sort/hierarchical_sorting.hpp"

#include "search/binary_search.hpp"
#include "search/linear_search.hpp"
*/

#include "sort/radix_sort.hpp"

template<typename T> void print_array(T* arr, size_t const& length);

bool cp_fn( int const& a, int const& b ) {
    return a < b;
}

int main(){

    unsigned int arr[10] = { 120,999,80000,700,6213,5156,424563,314,33234,1000000 };
    //int arr[12] = { 95,11,12,10,9,7,16,8,5,4,2,1 };

    print_array<unsigned int>(arr, (sizeof(arr) / sizeof(int)));

    sort::radix_sort(arr, (size_t)(sizeof(arr) / sizeof(int)) );

    print_array<unsigned int>( arr , (sizeof(arr) / sizeof(int)) );


    return 0;
}



template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}