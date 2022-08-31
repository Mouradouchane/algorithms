
#pragma once

    /*
    
        *** not stable yet, under construction ***

    */ 

namespace sort {

    // function for testing 
    bool comp(int& a, int& b) {
        return (a < b);
    }

    // testing currently on type 'int'
    void pyramid_sort(int arr[], size_t l, size_t r) {

        if (r <= l) return;

        int temp;

        if ((r - l + 1) == 2) {

            if (arr[l] > arr[r]) {

                temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;

            }

            return;
        }

        if ((r - l + 1) == 3) {

            if (arr[l] > arr[r]) {

                temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;

            }

            if (arr[l + 1] < arr[l]) {

                temp = arr[l];
                arr[l] = arr[l + 1];
                arr[l + 1] = temp;

            }


            if (arr[l + 1] > arr[r]) {

                temp = arr[r];
                arr[r] = arr[l + 1];
                arr[l + 1] = temp;

            }

            return;
        }


        // if l > r
        if (arr[l] > arr[r]) {

            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;

            temp = NULL;
        }

        size_t min_value_index = l;
        size_t max_value_index = r;

        for (size_t l_value = l + 1, r_value = r - 1; l_value <= r_value; l_value += 1, r_value -= 1) {

            // min < min_value_index
            if (arr[l_value] < arr[min_value_index]) {
                min_value_index = l_value;
            }

            // min > max_value_index
            if (arr[l_value] > arr[max_value_index]) {
                max_value_index = l_value;
            }

            // max < min_value_index
            if (arr[r_value] < arr[min_value_index]) {
                min_value_index = r_value;
            }
            // max > max_value_index
            if (arr[r_value] > arr[max_value_index]) {
                max_value_index = r_value;
            }

        }


        temp = arr[l];
        arr[l] = arr[min_value_index];
        arr[min_value_index] = temp;

        if (max_value_index == l) {
            max_value_index = min_value_index;
        }

        temp = arr[r];
        arr[r] = arr[max_value_index];
        arr[max_value_index] = temp;


        pyramid_sort(arr, l + 1, r - 1);
    }


}