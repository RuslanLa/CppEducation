#pragma once
#include <InsertionSortEnumerator.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class insertion_sort_desc_enumerator: public insertion_sort_enumerator
{
public:
	bool next() override;
	bool previous() override;
    void set_previous_to_inderect() const override;

	insertion_sort_desc_enumerator(vector<int32_t>& vector);
};
