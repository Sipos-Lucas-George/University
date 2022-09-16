//
// Created by lukyl on 10/06/2022.
//

#include <algorithm>
#include "Observer.h"

void Subject::deleteObserver(Observer *o) {
    auto it = std::find(vector.begin(), vector.end(), o);
    if (it != vector.end())
        vector.erase(it);
}

void Subject::notify() {
    for (auto o : vector)
        o->update();
}
