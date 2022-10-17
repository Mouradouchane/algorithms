#include <iostream>
#include <cstdlib>  //required for rand(), srand()
#include <ctime>    //required for time()

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
#include "sort/binary_insertion_sort.hpp"

#include "search/binary_search.hpp"
#include "search/linear_search.hpp"

#include "reverse/reverse.hpp"
*/

#include "sort/tim_sort.hpp"


template<typename T> void print_array(T* arr, size_t const& length);

template<typename T> void print_array_and_check(
    T* arr, 
    size_t const& length , 
    bool &is_sorted , 
    bool (* const& compare_function)(T const& a, T const& b)
);

template<typename T> void fill_array(
    T* arr,
    size_t& size,
    T const& min_value, T const& max_value
);

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
    bool sort_rslt = false;
    std::srand(std::time(0));
    int sizes[6] = { 350,200,523,1254,426,64};
    int size = 201;
    // int size = sizes[ rand() % 5 ];

    int arr[201] = { 120,999,890,700,613,9,7,6,-5,4,-3,2,1,5156,425,314,334,9,};

    fill_array<int>(arr, (size_t&)size , -2 , 40 );
    // print_array< int>(arr, (sizeof(arr) / sizeof(int)));

    std::cout << "Generated Data Is ::\n";
    print_array_and_check<int>(arr, (size_t)size - 1, sort_rslt, cp_fn);

    sort::tim_sort<int>(arr, 0, (size_t)size - 1 , cp_fn);

    std::cout << '\n';
    std::cout << "Sorting Result Is ::\n";
    print_array_and_check<int>( arr , (size_t)size -1 , sort_rslt , cp_fn);
    std::cout << "Sorting Is ::\n" << (sort_rslt ? "true" : "false") << '\n';


    // delete arr;

    return 0;
}

template<typename T> void fill_array(T* arr, size_t& size , T const& min_value , T const& max_value) {

    std::srand(std::time(0));

    for (size_t i = 0; i < size; i += 1) arr[i] = (rand() % max_value + min_value);


}

template<typename T> void print_array(T* arr, size_t const& length) {

    for (size_t i = 0; i < length; i += 1) {
        std::cout << arr[i] << " , ";
    }

    std::cout << '\n';

}

template<typename T> void print_array_and_check(
        T* arr,
        size_t const& length,
        bool& is_sorted,
        bool (* const& compare_function)(T const& a, T const& b)
    ) {

    is_sorted = true;

    for (size_t i = 0 , c = 1 ; i < length ; i += 1 , c = c + 1 ) {

        if (arr[i] != arr[c] && !compare_function(arr[i], arr[c]) && is_sorted != NULL) is_sorted = false;
        std::cout << arr[i] << " ,";

    }

    std::cout << arr[length] << '\n';

}