#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
class MultiMapIterator;

struct Node {
    TValue value = NULL_TVALUE;
    Node* next = nullptr;
    Node* prev = nullptr;
};

typedef std::pair<TKey, Node*> TArray;

class MultiMap
{
	friend class MultiMapIterator;

private:
    TArray * array;
    int sizeOfArray;
    int capacity;

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//destructor
	~MultiMap();

    //modifies the values of those keys from the map that are in m to be equal to their value from m
    //returns the number of modified pairs
    int updateValues(MultiMap& m);
};

