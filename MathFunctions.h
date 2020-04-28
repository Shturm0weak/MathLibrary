#pragma once

namespace functions {
	template< typename T >
	void sort(T arr[], unsigned int length);

	template< typename T >
	void sort(T arr[], unsigned int length) {
		for (unsigned int i = 0; i < length - 1; i++)
		{
			for (unsigned int j = 0; j < length - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1]) {
					T temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}