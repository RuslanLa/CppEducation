#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include <InsertionSortEnumerator.h>

class InsertionSorter
{
private:
	static void sort(insertion_sort_enumerator* enumerator);
public:
	 void sort(std::vector<int32_t>& arr);
	 void descSort(std::vector<int32_t>& arr);
	 static void sortArray(std::vector<int32_t>& arr);
	 static void sortArrayDesc(std::vector<int32_t>& arr);
};
