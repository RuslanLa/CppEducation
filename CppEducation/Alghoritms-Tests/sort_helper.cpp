#include "pch.h"
#include "sort_helper.h"

bool checkArrayHasSeveralElements(vector<int32_t>& sortedArray)
{
	return sortedArray.size() > 1;
}

void assertArraySorted(vector<int32_t>& sortedArray)
{
	const size_t arraySize = sortedArray.size();
	if (arraySize <= 1)
	{
		return;
	}
	for (size_t i = 1; i < arraySize; i++)
	{
		ASSERT_TRUE(sortedArray[i] >= sortedArray[i - 1]);
	}
}

void assertArraySortedDesc(vector<int32_t>& sortedArray)
{
	const size_t arraySize = sortedArray.size();
	if (arraySize <= 1)
	{
		return;
	}
	for (size_t i = 1; i < arraySize; i++)
	{
		ASSERT_TRUE(sortedArray[i] <= sortedArray[i - 1]);
	}
}
