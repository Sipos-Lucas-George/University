#include "Set.h"
#include "SetITerator.h"

// Tetha(1)
Set::Set() {
	this->first = nullptr;
	this->capacity = 0;
}

// O(nrOfElements)
bool Set::add(TElem elem) {
	if (this->first == nullptr) {
		this->first = new Node;
		this->first->value = elem;
		++this->capacity;
		return true;
	}
	if (this->first->next == nullptr) {
		if (this->first->value == elem)
			return false;
		this->first->next = new Node;
		this->first->next->value = elem;
		++this->capacity;
		return true;
	}
	Node* current = this->first;
	Node* add = new Node;
	while (current != nullptr) {
		if (current->value == elem)
			return false;
		add = current;
		current = current->next;
	}
	current = new Node;
	current->value = elem;
	add->next = current;
	++this->capacity;
	return true;
}

// O(nrOfElements)
bool Set::remove(TElem elem) {
	if (this->first == nullptr)
		return false;
	if (this->first->value == elem) {
		Node* aux = this->first;
		this->first = this->first->next;
		delete aux;
		--this->capacity;
		return true;
	}
	Node* current = this->first;
	while (current->next != nullptr) {
		if (current->next->value == elem) {
			Node* aux = current->next;
			current->next = aux->next;
			delete aux;
			--this->capacity;
			return true;
		}
		current = current->next;
	}
	return false;
}

// O(nrOfElements)
bool Set::search(TElem elem) const {
	Node* current = this->first;
	while (current != nullptr) {
		if (current->value == elem)
			return true;
		current = current->next;
	}
	return false;
}

// Tetha(1)
int Set::size() const {
	return this->capacity;
}

// Tetha(1)
bool Set::isEmpty() const {
	return (this->first == nullptr) ? true : false;
}

// Tetha(nrOfElements)
Set::~Set() {
	Node* current = this->first;
	while (current != nullptr) {
		Node* aux = current;
		current = current->next;
		delete aux;
	}
}

// Tetha(nrOfElements)
int Set::getRange() const
{
	if (this->first == nullptr)
		return -1;
	int maxValue = this->first->value, minValue = this->first->value;
	Node* current = this->first->next;
	while (current != nullptr) {
		if (maxValue < current->value)
			maxValue = current->value;
		else if (minValue > current->value)
			minValue = current->value;
		current = current->next;
	}
	return maxValue - minValue;
}

// Tetha(1)
SetIterator Set::iterator() const {
	return SetIterator(*this);
}


