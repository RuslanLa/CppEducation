#include <InsertionSortDescEnumerator.h>
bool insertion_sort_desc_enumerator::next()
{
	if(this -> current_direct_position_ <= 0)
	{
		return false;
	}
	this->current_direct_position_--;
	this->current_indirect_position_ = this->current_direct_position_;
	this->curElement = this->_vector[current_direct_position_];
	return true;
}

bool insertion_sort_desc_enumerator::previous()
{
	if (this->current_indirect_position_ >= max_index_ || this->_vector[current_indirect_position_ + 1] <= this->curElement)
	{
		return false;
	}
	this->current_indirect_position_++;
	return true;
}

void insertion_sort_desc_enumerator::set_previous_to_inderect() const
{
	this->_vector[this->current_indirect_position_ - 1] = this->_vector[this->current_indirect_position_];
}

insertion_sort_desc_enumerator::insertion_sort_desc_enumerator(vector<int32_t>& vector): insertion_sort_enumerator(vector)
{
	this->current_direct_position_ = max_index_;
	this->current_indirect_position_ = max_index_;
}
