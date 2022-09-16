#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	if (this->col.sizeOfArray != 0) {
		this->currentPosition = 0;
		this->currentKey = this->col.array[0].first;
		this->currentNode = this->col.array[0].second;
	}
	else {
		this->currentPosition = -1;
	}
}

TElem MultiMapIterator::getCurrent() const{
	if (this->currentPosition == -1)
		throw std::exception();
	return std::make_pair(this->currentKey, this->currentNode->value);
}

bool MultiMapIterator::valid() const {
	return this->currentPosition != -1;
}

void MultiMapIterator::next() {
	if (this->currentPosition == -1)
		throw std::exception();
	if (this->currentNode->next == nullptr) {
		++this->currentPosition;
		if (this->currentPosition > this->col.sizeOfArray - 1)
			this->currentPosition = -1;
		else {
			this->currentKey = this->col.array[this->currentPosition].first;
			this->currentNode = this->col.array[this->currentPosition].second;
		}
	}
	else
		this->currentNode = this->currentNode->next;
}

void MultiMapIterator::first() {
	this->currentPosition = 0;
	this->currentKey = this->col.array[0].first;
	this->currentNode = this->col.array[0].second;
}

