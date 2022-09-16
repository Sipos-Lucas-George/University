#include "Matrix.h"
#include <iostream>
#include <exception>
using namespace std;

// O(nrLines * nrCols)
Matrix::Matrix(int nrLines, int nrCols) {
	if (nrLines <= 0 || nrCols <= 0) {
		throw std::exception();
	}
	this->rows = nrLines;
	this->cols = nrCols;
	this->numberOfElements = 0;
	this->valueArray = new int[nrLines * nrCols];
	for (int i = 0;i < nrLines * nrCols;i++)
		this->valueArray[i] = -1;
	this->rowIndexes = new int[nrLines * nrCols];
	for (int i = 0;i < nrLines * nrCols;i++)
		this->rowIndexes[i] = -1;
	this->colPointer = new int[nrCols];
	for (int i = 0;i < nrCols;i++)
		this->colPointer[i] = -1;
}

// Teta(1)
int Matrix::nrLines() const {
	return this->rows;
}

// Teta(1)
int Matrix::nrColumns() const {
	return this->cols;
}

// O(n)
TElem Matrix::element(int i, int j) const {
	if (i < 0 || i >= this->rows || j < 0 || j >= this->cols) {
		throw std::exception();
	}
	if (this->colPointer[j] == -1)
		return NULL_TELEM;
	int startOfSearch = this->colPointer[j];
	if (this->rowIndexes[startOfSearch] == i)
		return this->valueArray[this->colPointer[j]];
	int endOfSearch = NULL_TELEM;
	for (int l = j + 1; l < this->cols;l++) {
		if (this->colPointer[l] != -1) {
			endOfSearch = this->colPointer[l] - 1;
			break;
		}
	}
	if (endOfSearch == NULL_TELEM)
		endOfSearch = this->numberOfElements;
	return binarySearchConst(startOfSearch + 1, endOfSearch, i);
}

// O(numberOfElements)
TElem Matrix::modify(int i, int j, TElem e) {
	if (i < 0 || i >= this->rows || j < 0 || j >= this->cols) {
		throw std::exception();
	}
	int returnedValue = element(i, j);
	if (returnedValue == e)
		return e;
	if (returnedValue != NULL_TELEM) {
		int startOfSearch = this->colPointer[j];
		if (this->rowIndexes[startOfSearch] == i) {
			this->valueArray[startOfSearch] = e;
			return returnedValue;
		}
		int endOfSearch = NULL_TELEM;
		for (int l = j + 1; l < this->cols;l++) {
			if (this->colPointer[l] != -1) {
				endOfSearch = this->colPointer[l] - 1;
				break;
			}
		}
		if (endOfSearch == NULL_TELEM)
			endOfSearch = this->numberOfElements;
		int positionOfSearch = binarySearch(startOfSearch + 1, endOfSearch, i);
		this->valueArray[positionOfSearch] = e;
		return returnedValue;
	}
	if (returnedValue == NULL_TELEM) {
		this->numberOfElements++;
		int startSearch = this->colPointer[j], position = -1;
		if (startSearch != -1) {
			int endSearch = NULL_TELEM;
			for (int l = j + 1;l < this->cols;l++) {
				if (-1 != this->colPointer[l]) {
					endSearch = this->colPointer[l];
					break;
				}
			}
			if (endSearch == NULL_TELEM)
				endSearch = this->numberOfElements;
			position = binarySearch(startSearch, endSearch - 1, i);
			for (int l = this->numberOfElements;l > position;l--) {
				this->valueArray[l] = this->valueArray[l - 1];
				this->rowIndexes[l] = this->rowIndexes[l - 1];
			}
			this->valueArray[position] = e;
			this->rowIndexes[position] = i;
			if (position == startSearch)
				this->colPointer[j] = position;
			for (int l = j + 1;l < this->cols;l++)
				if (this->colPointer[l] != -1)
					this->colPointer[l]++;
			return NULL_TELEM;
		}
		else {
			for (int l = j - 1;l >= 0;l--) {
				if (-1 != this->colPointer[l]) {
					startSearch = this->colPointer[l];
					break;
				}
			}
			if (startSearch == -1)
				position = 0;
			else {
				for (int l = j + 1;l < this->cols;l++) {
					if (-1 != this->colPointer[l]) {
						position = this->colPointer[l];
						break;
					}
				}
				if (position == -1)
					position = this->numberOfElements;
			}
			for (int l = this->numberOfElements;l > position;l--) {
				this->valueArray[l] = this->valueArray[l - 1];
				this->rowIndexes[l] = this->rowIndexes[l - 1];
			}
			int getValueOnPosition = this->valueArray[position];
			if (getValueOnPosition == -1)
				getValueOnPosition = 0;
			this->valueArray[position] = e;
			this->rowIndexes[position] = i;
			this->colPointer[j] = position;
			for (int l = j + 1;l < this->cols;l++)
				if (this->colPointer[l] != -1)
					this->colPointer[l]++;
			return getValueOnPosition;
		}
	}
}

// O(numberOfElements)
void Matrix::setElemsOnCol(int col, TElem elem) {
	if (col < 0 || col >= this->rows) {
		throw std::exception();
	}
	for (int i = 0; i < this->rows; i++) {
		int val = this->modify(i, col, elem);
	}
}

// O(log(n))
int Matrix::binarySearchConst(int left, int right, int x) const {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (this->rowIndexes[mid] == x)
			return this->valueArray[mid];
		if (this->rowIndexes[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return NULL_TELEM;
}

// O(log(n))
int Matrix::binarySearch(int left, int right, int x){
	while (left <= right) {
		int mid = (left + right) / 2;
		if (this->rowIndexes[mid] == x)
			return mid;
		if (this->rowIndexes[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}
