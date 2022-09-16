#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());

    SortedMultiMap map = SortedMultiMap(relation1);
    map.add(1, 2);
    map.add(1, 3);
    map.add(1, 4);
    map.add(1, 2);
    map.replace(1, 2, 7);
    SMMIterator iterator = map.iterator();
    iterator.first();
    int count = 0;
    while(iterator.valid()){
        std::cout << iterator.getCurrent().first << " " << iterator.getCurrent().second;
        if(count == 0 || count == 3)
            assert(iterator.getCurrent().second == 7);
        else if(count == 1)
            assert(iterator.getCurrent().second == 4);
        else
            assert(iterator.getCurrent().second == 3);
        ++count;
        iterator.next();
    }
    map.replace(1, 7, 1);
    map.replace(1, 4, 1);
    map.replace(1, 3, 1);
    iterator.first();
    while(iterator.valid()){
        assert(iterator.getCurrent().second == 1);
        iterator.next();
    }
}

