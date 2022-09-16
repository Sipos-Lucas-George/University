#pragma once
#define RESIZE 2

template<typename T>
class DynamicVector {
private:
    T* elements;
    int size{};
    int capacity{};

public:
    // default constructor for DynamicVector
    explicit DynamicVector(int capacity = 10);

    // copy constructor for a DynamicVector
    DynamicVector(const DynamicVector<T>& vector);

    // destructor for DynamicVector
    ~DynamicVector();

    // add an element to the current DynamicVector
    void addItem(const T& element);

    // delete an element from the current DynamicVector
    void deleteItem(int position);

    // update an element on a given position from the current DynamicVector
    void updateItem(int position, const T& element);

    // resize the current DynamicVector
    void resize();

    T& operator[](int index);
    int getSize() const { return this->size; }
    int getCapacity() const { return this->capacity; }
    T& getElement(const int position) const { return this->elements[position]; }
};

template<typename T>
DynamicVector<T>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elements = new T[capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T> &vector) {
    this->size = vector.getSize();
    this->capacity = vector.getCapacity();
    this->elements = new T[this->capacity];
    for (int i = 0; i < this->size; ++i)
        this->elements[i] = vector.getElement(i);
}

template<typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] this->elements;
}

template<typename T>
void DynamicVector<T>::addItem(const T &element) {
    if (this->size == this->capacity)
        this->resize();
    this->elements[this->size++] = element;
}

template<typename T>
void DynamicVector<T>::deleteItem(int position) {
    for (int i = position; i < this->size - 1; ++i)
        this->elements[i] = this->elements[i + 1];
    --this->size;
}

template<typename T>
void DynamicVector<T>::updateItem(int position, const T& element) {
    this->elements[position] = element;
}

template<typename T>
void DynamicVector<T>::resize() {
    this->capacity *= RESIZE;

    auto* els = new T[this->capacity];
    for (int i = 0; i < this->size; ++i)
        els[i] = this->elements[i];

    delete[] this->elements;
    this->elements = els;
}

template<typename T>
T& DynamicVector<T>::operator[](int index) {
    return this->elements[index];
}
