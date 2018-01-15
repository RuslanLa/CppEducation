#include "pch.h"
#include "../Alghoritms/InsertionSorter.h"
#include "sort_helper.h"

TEST(InsertionSortArraySorted, SortTests) {
	const vector<int32_t> arr = vector<int32_t>{ 1, 2, 4, 6 };
	const vector<int32_t> sortResult = InsertionSorter::sort(arr);
	assertArraySorted(sortResult);
}

TEST(InsertionSortArrayWithDublicatesSorted, SortTests) {
	const vector<int32_t> arr = vector<int32_t>{ 5, 5, 2, 2, 30, 29, 40, 35, 99, 100, 1, 4  };
	const vector<int32_t> sortResult = InsertionSorter::sort(arr);
	assertArraySorted(sortResult);
}

TEST(InsertionSortReversedArraySorted, SortTests) {
    vector<int32_t> arr = vector<int32_t>(100);
	for (int i = 0 ; i < arr.size(); i++)
	{
		arr[i] = arr.size() - i;
	}
	const vector<int32_t> sortResult = InsertionSorter::sort(arr);
	assertArraySorted(sortResult);
}