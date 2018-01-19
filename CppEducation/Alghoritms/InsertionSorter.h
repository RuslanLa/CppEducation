#pragma once
#include "InsertionSortEnumerator.h"
#include "sorter.h"

class InsertionSorter: sorter
{
private:
	static void sort(insertion_sort_enumerator* enumerator);
public:
	 void sort(std::vector<int32_t>& arr) override;
	 void descSort(std::vector<int32_t>& arr) override;
	 static void sortArray(std::vector<int32_t>& arr);
	 static void sortArrayDesc(std::vector<int32_t>& arr);
};
