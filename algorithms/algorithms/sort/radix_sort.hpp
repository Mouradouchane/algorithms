#include <vector>
#include <string>

#pragma once

namespace sort {

	// private anonymouse namespace for radix_sort functions
	namespace {
		/*
		void sort_process(unsigned int* arr, size_t const& lenght , std::vector<unsigned int> * pins ,size_t divide_value = 1) {

		}
		*/


	} // end of anonymouse namespace


	void radix_sort(unsigned int* arr , size_t const& length) {

		std::vector<unsigned int> pins[10];

		unsigned int max_value = 0;
		unsigned int passes_count = 1;
		unsigned int divide_value = 1;

		unsigned int index = 0;

		for (unsigned int i = 0; i < length; i += 1) {

			if (arr[i] > max_value) max_value = arr[i];

			index = arr[i] / 1 % 10;

			pins[index].push_back(arr[i]);

		}

		for (unsigned int i = 0 , p = 0; i < 10; i += 1) {
			
			for (unsigned int c = 0; c < pins[i].size(); c += 1 ) {

				arr[p] = pins[i][c];
				p += 1;

			}

			pins[i].clear();
		}

		passes_count = (unsigned int)(std::to_string(max_value).length());
		divide_value = 10;
		index = 0;

		for (unsigned int pass = 2; pass <= passes_count; pass += 1) {

			for (unsigned int i = 0; i < length; i += 1) {

				index = arr[i] / divide_value % 10;

				pins[index].push_back(arr[i]);

			}

			for (unsigned int k = 0, p = 0; k < 10; k += 1) {

				for (unsigned int c = 0; c < pins[k].size(); c += 1) {

					arr[p] = pins[k][c];
					p += 1;

				}

				pins[k].clear();
			}

			divide_value *= 10;
		}

		//delete pins;
		//delete 
	}

}