#include "InsertionSorter.h"
#include "InsertionSortEnumerator.h"
#include <memory>
#include "InsertionSortDescEnumerator.h"

void InsertionSorter::sort(insertion_sort_enumerator* enumerator)
{
	while (enumerator->next())
	{
		while (enumerator->previous())
		{
			enumerator->set_previous_to_inderect();
		}
		enumerator->set_direct_to_inderect();
	}
}

std::vector<int32_t> InsertionSorter::sort(std::vector<int32_t>& arr)
{
    const auto enumerator = new insertion_sort_enumerator(arr);
	sort(enumerator);
	delete enumerator;
	return arr;
}


std::vector<int32_t> InsertionSorter::descSort(std::vector<int32_t>& arr)
{
	const auto enumerator = new insertion_sort_desc_enumerator(arr);
	sort(enumerator);
	delete enumerator;
	return arr;
}
