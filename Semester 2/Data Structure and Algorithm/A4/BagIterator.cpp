#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c){
    this->position = 0;
    this->frequency = 0;
    this->first();
}

void BagIterator::first() {
    if (this->bag.isEmpty())
        return;
    this->position = 0;
    while(this->bag.elements[this->position].first == NULL_TELEM)
        ++this->position;
    this->frequency = 1;
}


void BagIterator::next() {
	if (this->bag.isEmpty() || this->frequency == 0)
        throw std::exception();
    if (this->frequency < this->bag.elements[this->position].second)
        ++this->frequency;
    else{
        this->frequency = 1;
        ++this->position;
        while(this->bag.elements[this->position].first == NULL_TELEM && this->position < this->bag.capacity)
            ++this->position;
        if (this->position == this->bag.capacity){
            this->frequency = 0;
        }
    }
}

bool BagIterator::valid() const {
	return this->frequency > 0;
}

TElem BagIterator::getCurrent() const{
    if (this->valid())
        return this->bag.elements[this->position].first;
	throw std::exception();
}
