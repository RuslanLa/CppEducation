#pragma once
#include "InsertionSortEnumerator.h"

class InsertionSorter
{
private:
	static void sort(insertion_sort_enumerator* enumerator);
public:
	static std::vector<int32_t> sort(std::vector<int32_t>& arr);
	static std::vector<int32_t> descSort(std::vector<int32_t>& arr);
};
