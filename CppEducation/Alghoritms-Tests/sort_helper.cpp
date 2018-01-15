#include "pch.h"
#include "sort_helper.h"

void assertArraySorted(vector<int32_t> sortedArray)
{
	if(sortedArray.size() <= 1)
	{
		return;
	}
	for (int i = 1; i < sortedArray.size(); i++)
	{
		ASSERT_TRUE(sortedArray[i] >= sortedArray[i - 1]);
	}
}
