#include "SetIterator.h"
#include "Set.h"

SetIterator::SetIterator(const Set& m) : set(m)
{
	this->_first = m.first;
	this->current = m.first;
}


void SetIterator::first() {
	this->current = this->_first;
}


void SetIterator::next() {
	if (this->valid())
		this->current = this->current->next;
	else
		throw std::exception();
}


TElem SetIterator::getCurrent()
{
	if (this->current == nullptr)
		throw std::exception();
	return this->current->value;
}

bool SetIterator::valid() const {
	return (this->set.size() != 0 && this->current != nullptr) ? true : false;
}



