#include <iostream>

/*
#include "sort/heap_sort.hpp"
#include "sort/linear_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/merge_sort.hpp"
#include "sort/hierarchical_sorting.hpp"
#include "sort/radix_sort.hpp"
#include "sort/insertion_sort.hpp"
#include "sort/selection_sort.hpp"
#include "sort/bubble_sort.hpp"
#include "sort/shell_sort.hpp"
#include "sort/counting_sort.hpp"

#include "search/binary_search.hpp"
#include "search/linear_search.hpp"

#include "reverse/reverse.hpp"
*/

// #include "sort/tim_sort.hpp"
#include "sort/binary_insertion_sort.hpp"


template<typename T> void print_array(T* arr, size_t const& length);

bool cp_fn( int const& target, int const& element ) {
    return target < element;
}

int main(){

    /*
    int arr[9] = { 4,88,-1,5,-5,47,0,61,1 };
    int arr[9] = { 9,-8,7,6,-5,4,-3,2,1 };
    unsigned int arr[10] = { 4,4,4,4,100, 4,20,50,4,4 };
    int arr[20] = { 120,999,890,700,6213,5156,42563,314,33234,9,-8,7,6,-5,4,-3,2,1 };
    int arr[11] = { 11,10,9,8,7,6,5,4,3,2,1 };
    int arr[10] = { 3,7,6,5,4,0,9,8,1,11 };
    */
    int arr[15] = {120,999,80000,700,6213,5156,424563,314,33234,1215649,12,7,86,2,7};

    print_array< int>(arr, (sizeof(arr) / sizeof(int)));

    sort::binary_insertion_sort<int>(arr, 0, (size_t)(sizeof(arr) / sizeof(int)) - 1 , cp_fn);

    print_array< int>( arr , (sizeof(arr) / sizeof(int)) );

    return 0;
}



template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}