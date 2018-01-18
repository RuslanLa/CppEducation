#include "pch.h"
#include "../Alghoritms/InsertionSorter.h"
#include "sort_helper.h"

TEST(InsertionSortArraySorted, SortTests) {
    vector<int32_t> arr = vector<int32_t>{ 1, 2, 4, 6 };
	InsertionSorter::sort(arr);
	assertArraySorted(arr);
}

TEST(InsertionSortArrayWithDublicatesSorted, SortTests) {
    vector<int32_t> arr = vector<int32_t>{ 5, 5, 2, 2, 30, 29, 40, 35, 99, 100, 1, 4  };
	InsertionSorter::sort(arr);
	assertArraySorted(arr);
}

TEST(InsertionSortReversedArraySorted, SortTests) {
    vector<int32_t> arr = vector<int32_t>(100);
	for (size_t i = 0 ; i < arr.size(); i++)
	{
		arr[i] = arr.size() - i;
	}
	InsertionSorter::sort(arr);
	assertArraySorted(arr);
}