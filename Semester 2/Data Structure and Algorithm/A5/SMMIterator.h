#pragma once
#include <stack>
#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);
    Node* current;
    std::stack<Node*> stack;

public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};
