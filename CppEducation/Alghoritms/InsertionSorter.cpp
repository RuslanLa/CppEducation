#include "InsertionSorter.h"

std::vector<int32_t> InsertionSorter::sort(std::vector<int32_t>& arr)
{
	for (int32_t i = 1; i < arr.size(); i++)
	{
		const auto curElement = arr[i];
		int32_t j = i;
		while (j >= 1 && arr[j - 1] > curElement)
		{
			arr[j] = arr[j - 1];
			j--;
		}

		arr[j] = curElement;
	}
	return arr;
}
