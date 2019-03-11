#include <InsertionSortEnumerator.h>
insertion_sort_enumerator::insertion_sort_enumerator(vector<int32_t>& vector):_vector(vector)
{
	this->max_index_ = vector.size() - 1;
	this->current_direct_position_ = 0;
	this->current_indirect_position_ = 0;
	this->curElement = 0;
}

bool insertion_sort_enumerator::next()
{
	if (this->current_direct_position_ >= this->max_index_)
	{
		return false;
	}
	this->current_direct_position_++;
	this->current_indirect_position_ = this->current_direct_position_;
	this->curElement = _vector[current_direct_position_];
	return true;
}

int32_t insertion_sort_enumerator::inderectTraversingElement() const
{
	return this->_vector[current_indirect_position_];
}

bool insertion_sort_enumerator::previous()
{
	if (this->current_indirect_position_ <= 0 || this->_vector[current_indirect_position_ - 1] <= this->curElement)
	{
		return false;
	}
	this->current_indirect_position_--;
	return true;
}

void insertion_sort_enumerator::set_previous_to_inderect() const
{
	this->_vector[this->current_indirect_position_+1] = this->_vector[this->current_indirect_position_];
}

void insertion_sort_enumerator::set_direct_to_inderect() const
{
	this->_vector[this->current_indirect_position_] = this->curElement;
}

