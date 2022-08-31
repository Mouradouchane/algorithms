#include <iostream>

#include "sort/linear_sort.hpp"
#include "sort/hierarchical_sorting.hpp"

template<typename T> void print_array(T* arr, size_t const& length);

int main(){

    int arr[8] = {4,8,22,1,6,112,3,33};

    sort::pyramid_sort( arr, 0 , (sizeof(arr) / sizeof(int))-1 );

    print_array<int>( arr , (sizeof(arr) / sizeof(int)) );

    return 0;
}



template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}