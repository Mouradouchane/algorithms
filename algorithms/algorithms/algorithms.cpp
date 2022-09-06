#include <iostream>

//#include "sort/linear_sort.hpp"
//#include "sort/hierarchical_sorting.hpp"
#include "sort/heap_sort.hpp"

//#include "search/binary_search.hpp"
//#include "search/linear_search.hpp"

template<typename T> void print_array(T* arr, size_t const& length);

int main(){

    int arr[12] = { 144,8,10,3,9,42,55,100,7,56,2,13 };

    print_array<int>(arr, (sizeof(arr) / sizeof(int)));

    sort::heap_sort<int>(arr, (size_t)(sizeof(arr) / sizeof(int)) - 1, 
        []( int const& a , int const& b ) -> bool { return a > b; } 
    );

    print_array<int>( arr , (sizeof(arr) / sizeof(int)) );

    /*
        std::cout << "target found : " << search::linear_search_b<int>(arr, 11, 10) << '\n';
    */

    return 0;
}



template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}