#include "Bag.h"
#include "BagIterator.h"
#include <iostream>
using namespace std;

//Theta(1)
Bag::Bag() {
	this->capacity = SIZE;
    this->_size = 0;
    for (auto& i : this->elements){
        i.first = NULL_TELEM;
        i.second = NULL_TELEM;
    }
}

//O(SIZE/10)
void Bag::add(TElem elem) {
	++this->_size;
    unsigned int position = hash(elem, 0);
    if (this->elements[position].first == NULL_TELEM)
        this->elements[position] = std::make_pair(elem, 1);
    else if (this->elements[position].first == elem)
        ++this->elements[position].second;
    else{
        int i = 1;
        while (this->elements[position].first != NULL_TELEM && this->elements[position].first != elem && i < SIZE){
            position = this->hash(elem, i);
            ++i;
        }
        if (this->elements[position].first == NULL_TELEM)
            this->elements[position] = std::make_pair(elem, 1);
        else if (this->elements[position].first == elem)
            ++this->elements[position].second;
    }
}

//Theta(SIZE)
void Bag::addAll(const Bag& b) {
    for (int i = 0; i < this->capacity; ++i){
        this->elements[i].first = b.elements[i].first;
        this->elements[i].second = b.elements[i].first;
    }
    this->_size = b._size;
    this->capacity = b.capacity;
}

//O(SIZE/10)
bool Bag::remove(TElem elem) {
    int i = 0;
    unsigned int position = 0;
    while (i < SIZE/10) {
        position = hash(elem, i);
        if (this->elements[position].first == elem){
            if (this->elements[position].second == 1){
                this->elements[position] = std::make_pair(NULL_TELEM, NULL_TELEM);
                --this->_size;
                return true;
            }
            else{
                --this->elements[position].second;
                --this->_size;
                return true;
            }
        }
        ++i;
    }
	return false;
}

//O(SIZE/10)
bool Bag::search(TElem elem) const {
    int i = 0;
    unsigned int position = 0;
    while (i < SIZE/10) {
        position = hash(elem, i);
        if (this->elements[position].first == elem)
            return true;
        ++i;
    }
    return false;
}

//O(SIZE/10)
int Bag::nrOccurrences(TElem elem) const {
    int i = 0;
    unsigned int position = 0;
    while (i < SIZE/10) {
        position = hash(elem, i);
        if (this->elements[position].first == elem)
            return this->elements[position].second;
        ++i;
    }
    return 0;
}

//Theta(1)
int Bag::size() const {
	return this->_size;
}

//Theta(1)
bool Bag::isEmpty() const {
	return this->_size == 0;
}

//Theta(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

Bag::~Bag() = default;

//Theta(1)
unsigned int Bag::hash(int key, int multiplier) const {
    return (std::abs(key) + multiplier * multiplier) % this->capacity;
}
