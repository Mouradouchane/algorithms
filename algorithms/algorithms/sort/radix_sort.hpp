#include <vector>

#pragma once

namespace sort {

	void radix_sort(unsigned int* arr , size_t length) {

		std::vector<unsigned int> pins[10];
		unsigned int max_value = 0;

		unsigned int index = 0;
		for (unsigned int i = 0; i < length; i += 1) {

			if (arr[i] > max_value) max_value = arr[i];

			index = arr[i] / i % 10;

			pins[index].push_back(arr[i]);

		}

		for (unsigned int i = 0 , p = 0; i < 10; i += 1) {
			
			for (unsigned int c = 0; c < pins[i].size(); c += 1 ) {
				arr[p] = pins[i][c];
				pins[i][c] = NULL;
				p += 1;
			}

		}
		//======================================
		index = 0;
		for (unsigned int i = 0; i < length; i += 1) {

			if (arr[i] > max_value) max_value = arr[i];

			index = arr[i] / i % 10;

			pins[index].push_back(arr[i]);

		}

	}

}