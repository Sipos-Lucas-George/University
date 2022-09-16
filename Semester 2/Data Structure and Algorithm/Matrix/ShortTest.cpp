#include "Matrix.h"
#include <cassert>
#include <exception>

using namespace std;

void testSetElemsOnCol() {
	Matrix m(4, 4);
	m.setElemsOnCol(2, 4);
	for (int i = 0; i < 4; i++)
		assert(m.element(i, 2) == 4);
	m.modify(1, 1, 3);
	m.setElemsOnCol(1, 2);
	for (int i = 0; i < 4; i++)
		assert(m.element(i, 1) == 2);
	try {
		m.setElemsOnCol(-10, 0);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		m.setElemsOnCol(10, 0);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

}

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);
	testSetElemsOnCol();
}