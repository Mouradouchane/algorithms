
#pragma once

    /*
    
        *** not stable yet, under construction ***

    */ 

namespace sort {

    // private namespace for pyramid_sort functions
    namespace {

        // O( 1 )
        template<typename T> void swap(T& a, T& b) {

            T temp = a;
            a = b;
            b = temp;

        }


    }

    // O( ??? )
    template<typename T> void pyramid_sort(
        T * arr ,
        size_t l   , 
        size_t r   ,
        bool (*compare_function)( T const& target , T const& other_element )
    ) {

        if ((r - l + 1) < 2) return;

        if (!compare_function(arr[l], arr[r])) swap<T>(arr[l], arr[r]);

        
        size_t min_value_index = l;
        size_t max_value_index = r;

        for (size_t l_value = l + 1, r_value = r - 1; l_value <= r_value; l_value += 1, r_value -= 1) {

            // min < min_value_index
            if ( compare_function(arr[l_value] , arr[min_value_index]) ) {
                min_value_index = l_value;
            }
            // min > max_value_index
            if ( !compare_function(arr[l_value], arr[max_value_index]) ) {
                max_value_index = l_value;
            }

            // max < min_value_index
            if ( compare_function(arr[r_value] , arr[min_value_index]) ) {
                min_value_index = r_value;
            }
            // max > max_value_index
            if ( !compare_function(arr[r_value] , arr[max_value_index]) ) {
                max_value_index = r_value;
            }

        }

        if (max_value_index == l || min_value_index == r ) {
            swap<T>(arr[l], arr[r]);
        }
        else {
            swap<T>(arr[l], arr[min_value_index]);
            swap<T>(arr[r], arr[max_value_index]);
        }


        pyramid_sort<T>(arr, l + 1, r - 1 , compare_function);
    }


}