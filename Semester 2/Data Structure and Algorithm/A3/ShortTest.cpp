#include "ShortTest.h"
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <assert.h>
#include <vector>
#include<iostream>

void testAll() {
	MultiMap m;
	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);

	assert(m.size() == 6);

	assert(m.remove(5, 600) == false);
	assert(m.remove(1, 500) == true);

	assert(m.size() == 5);

    vector<TValue> v;
	v=m.search(6);
	assert(v.size()==0);

	v=m.search(1);
	assert(v.size()==1);

	assert(m.isEmpty() == false);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.getCurrent();
		im.next();
	}
	assert(im.valid() == false);
	im.first();
	assert(im.valid() == true);

    MultiMap map1;
    MultiMap map2;
    map1.add(1, 100);
    map1.add(2, 200);
    map1.add(3, 300);
    map1.add(1, 500);
    map1.add(2, 600);
    map1.add(4, 800);
    map2.add(1, 1000);
    map2.add(6, 2000);
    map2.add(3, 3000);
    map2.add(1, 5000);
    map2.add(10, 6000);
    map2.add(4, 8000);

    assert(map1.updateValues(map2) == 3);
    std::vector<int> vector = map1.search(1);
    assert(vector[0] == 5000);
    assert(vector[1] == 1000);
}
