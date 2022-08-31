#include <iostream>

#include "sort/linear_sort.hpp"
#include "sort/hierarchical_sorting.hpp"

#include "search/binary_search.hpp"
#include "search/linear_search.hpp"

template<typename T> void print_array(T* arr, size_t const& length);

int main(){

    int arr[12] = {1,2,3,4,5,6,7,8,11,12,15,16};

    print_array<int>( arr , (sizeof(arr) / sizeof(int)) );

    std::cout << "target found : " << search::linear_search_b<int>(arr, 11, 16 ) << '\n';
    std::cout << "target found : " << search::linear_search_b<int>(arr, 11, 17 ) << '\n';
    std::cout << "target found : " << search::linear_search_b<int>(arr, 11, -1 ) << '\n';
    std::cout << "target found : " << search::linear_search_b<int>(arr, 11, 10 ) << '\n';

    return 0;
}



template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}