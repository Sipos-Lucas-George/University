#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

//Tetha(1)
MultiMap::MultiMap() {
    this->array = new TArray[1000000];
    this->sizeOfArray = 0;
    this->capacity = 0;
}

//O(numberOfElements)
void MultiMap::add(TKey c, TValue v) {
	this->capacity++;
    Node* newNode = new Node;
    newNode->value = v;
    if (this->sizeOfArray == 0) {
        this->sizeOfArray++;
        this->array[0].first = c;
        this->array[0].second = newNode;
        return;
    }
    for (int i = 0; i < this->sizeOfArray; ++i) {
        if (this->array[i].first != c)
            continue;
        this->array[i].second->prev = newNode;
        newNode->next = this->array[i].second;
        this->array[i].second = newNode;
        return;
    }
    this->array[this->sizeOfArray].first = c;
    this->array[this->sizeOfArray].second = newNode;
    this->sizeOfArray++;
}

//O(numberOfElements * numberOfElementsInDLL)
bool MultiMap::remove(TKey c, TValue v) {
	for (int i = 0; i < this->sizeOfArray; ++i) {
        if (this->array[i].first == c) {
            Node* current = this->array[i].second;
            bool moreThanOne = true;
            int numberOfNodes = 0;
            while (current != nullptr) {
                ++numberOfNodes;
                if (current->value == v) {
                    --this->capacity;
                    if (numberOfNodes == 1) {
                        if (current->next == nullptr) {
                            moreThanOne = false;
                            delete current;
                        }
                        else {
                            this->array[i].second = current->next;
                            delete current;
                            this->array[i].second->prev = nullptr;
                        }
                    }
                    else {
                        if (current->next != nullptr) {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                            delete current;
                        }
                        else {
                            current->prev->next = nullptr;
                            delete current;
                        }
                    }
                    if (!moreThanOne) {
                        for (int j = i; j < this->sizeOfArray - 1; ++j)
                            this->array[j] = this->array[j + 1];
                        --this->sizeOfArray;
                    }
                    return true;
                }
                current = current->next;
            }
        }
    }
	return false;
}

//O(numberOfElements * DLL)
vector<TValue> MultiMap::search(TKey c) const {
    vector<TValue> vector;
    for (int i = 0; i < this->sizeOfArray; ++i) {
        if (this->array[i].first == c) {
            Node* current = this->array[i].second;
            while (current != nullptr) {
                vector.push_back(current->value);
                current = current->next;
            }
            return vector;
        }
    }
    return vector;
}

//Tetha(1)
int MultiMap::size() const {
	return this->capacity;
}

//Tetha(1)
bool MultiMap::isEmpty() const {
    return this->capacity == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

//Tetha(numberOfElements * DLL)
MultiMap::~MultiMap() {
	for (int i = 0; i < this->sizeOfArray; ++i){
        Node* current = this->array[i].second;
        while (current != nullptr) {
            Node* deleteNode = current;
            current = current->next;
            delete deleteNode;
        }
    }
    delete[] this->array;
}

//O(numberOfElements*numberOfElementsOfGivenMap)
int MultiMap::updateValues(MultiMap &m) {
    int modified = 0;
    for (int i = 0; i < this->sizeOfArray; ++i){
        for (int j = 0; j < m.sizeOfArray; ++j){
            if (m.array[j].first == this->array[i].first){
                ++modified;
                this->array[i] = m.array[j];
                break;
            }
        }
    }
    return modified;
}

