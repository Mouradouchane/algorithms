#include <iostream>

/*
#include "sort/heap_sort.hpp"
#include "sort/linear_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/merge_sort.hpp"
#include "sort/hierarchical_sorting.hpp"
#include "sort/radix_sort.hpp"

#include "search/binary_search.hpp"
#include "search/linear_search.hpp"
*/

#include "sort/insertion_sort.hpp"


template<typename T> void print_array(T* arr, size_t const& length);

bool cp_fn( int const& target, int const& element ) {
    return target < element;
}

int main(){

    //int arr[15] = { 120,999,80000,700,6213,5156,424563,314,33234,1215649,12,7,86,2,7 };
    int arr[9] = { 4,88,-1,5,-5,47,0,61,1 };

    print_array<int>(arr, (sizeof(arr) / sizeof(int)));

    sort::insertion_sort<int>(arr, 0 , (size_t)(sizeof(arr) / sizeof(int)) , cp_fn);

    print_array<int>( arr , (sizeof(arr) / sizeof(int)) );


    return 0;
}



template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}