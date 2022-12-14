#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>

FixedCapBiMap::FixedCapBiMap(int capacity) {
    if(capacity <= 0) {
        throw std::exception();
    }
	this->size_of_Values = 0;
    this->max_capacity = capacity;
    this->Values = new TElem[capacity];
}

FixedCapBiMap::~FixedCapBiMap() {
	delete this->Values;
}

bool FixedCapBiMap::add(TKey c, TValue v){
	if(this->size_of_Values == this->max_capacity)
    {
        throw std::exception();
    }
    int counter = 0;
    for(int i=0;i<this->size_of_Values;i++)
    {
        if(this->Values[i].first == c)
        {
            counter++;
            if (counter == 2) {
                break;
            }
        }
    }

    if(counter>=2)
    {
        return false;
    }

	this->Values[this->size_of_Values].first = c;
	this->Values[this->size_of_Values].second = v;

    this->size_of_Values++;
    return true;
}

ValuePair FixedCapBiMap::search(TKey c) const{
//	TElem result = std::pair<TValue, TValue>(NULL_TVALUE, NULL_TVALUE);
	TElem result = ValuePair(NULL_TVALUE, NULL_TVALUE);
    int counter=0;
    for(int i=0;i<this->size_of_Values; i++)
    {
        if(this->Values[i].first == c)
        {
            if(counter==0)
            {
                result.first =this->Values[i].second;
            }
            else
            {
                result.second =this->Values[i].second;
            }
            counter++;
        }
    }

	return result;
}

bool FixedCapBiMap::remove(TKey c, TValue v){
    int i;
	for(i=0;i<this->size_of_Values;i++)
        if(this->Values[i].first == c && this->Values[i].second == v) {
//            this->Values[i]=this->Values[this->size_of_Values-1];
//            this->size_of_Values--;
//            return true;
            break;
        }
    if(i < this->size_of_Values)
    {
        this->Values[i]=this->Values[this->size_of_Values-1];
        this->size_of_Values--;
        return true;
    }

	return false;
}

ValuePair FixedCapBiMap::removeKey(TKey k) {
    TElem result = search(k);
    
    if (result.first == NULL_TVALUE)
        return result;
    else
    {
        remove(k, result.first);
        if (result.second == NULL_TVALUE)
            return result;
        remove(k, result.second);
        return result;
    }
}

int FixedCapBiMap::size() const {
	return this->size_of_Values;
}

bool FixedCapBiMap::isEmpty() const{
    if (this->size_of_Values == 0)
        return true;
	return false;
//    return this->size_of_Values == 0;
}


bool FixedCapBiMap::isFull() const {
	return this->size_of_Values == this->max_capacity;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}



