#pragma once

#include "../Domain/Player.h"
#include <cstring>

template <typename TElement>
class DynamicVector
{
private:
    TElement* elems;
    int size{};
    int capacity{};

public:
    // default constructor for a DynamicVector
    explicit  DynamicVector();
    explicit DynamicVector(int capacity);

    // copy constructor for a DynamicVector
    DynamicVector(const DynamicVector& v);
    ~DynamicVector();

    // assignment operator for a DynamicVector
    DynamicVector& operator=(const DynamicVector& v);

    // Adds an element to the current DynamicVector.
    int add(const TElement& e);

    // Removes the element from the specified index
    void remove(int index);

    TElement& operator[](int pos);

    void operator+(const TElement& e);

    int getSize() const;

private:
    // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
    void resize(int size);
};

template<typename TElement>
DynamicVector<TElement>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elems = new TElement[capacity];
}

template<typename TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector& v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new TElement[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];
}

template<typename TElement>
DynamicVector<TElement>::~DynamicVector() {
    delete[] this->elems;
}

template<typename TElement>
DynamicVector<TElement>& DynamicVector<TElement>::operator=(const DynamicVector& v)
{
    if (this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elems;
    this->elems = new TElement[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}

template<typename TElement>
int DynamicVector<TElement>::add(const TElement& e)
{
    if (valid(e)) {
        if (this->size == this->capacity)
            this->resize(this->size * 2);
        this->elems[this->size] = e;
        this->size++;

        return 1;
    } else {
        return 0;
    }
}

template<typename TElement>
void DynamicVector<TElement>::resize(int new_size)
{
    this->capacity = new_size;

    auto* els = new TElement[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i] = this->elems[i];

    delete[] this->elems;
    this->elems = els;
}
template<typename TElement>
TElement & DynamicVector<TElement>::operator[](int pos)
{
    return this->elems[pos];
}

template<typename TElement>
int DynamicVector<TElement>::getSize() const
{
    return this->size;
}

template<typename TElement>
void DynamicVector<TElement>::remove(int index) {
    for (int i = index; i < this->size - 1; ++i) {
        this->elems[i] = this->elems[i+1];
    }
    --this->size;
}

template<typename TElement>
DynamicVector<TElement>::DynamicVector() {
    this->elems = new TElement [0];
    this->size = 0;
    this->capacity = 0;
}

template<typename TElement>
void DynamicVector<TElement>::operator+(const TElement& e) {
    if (valid(e)) {
        if (this->size == this->capacity)
            this->resize(this->size + 1);
        this->elems[this->size] = e;
        this->size++;
    }
}
