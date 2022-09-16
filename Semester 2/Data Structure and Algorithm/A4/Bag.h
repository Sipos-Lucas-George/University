#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#include <utility>

#define NULL_TELEM -111111
#define SIZE 100001
typedef int TElem;
typedef std::pair<int, int> TPair;
class BagIterator; 
class Bag {

private:
	//TODO - Representation
    TPair elements[SIZE];
    int capacity;
    int _size;

    unsigned int hash(int key, int multiplier) const;
	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//adds all elements of b in the bag
	void addAll(const Bag& b);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};