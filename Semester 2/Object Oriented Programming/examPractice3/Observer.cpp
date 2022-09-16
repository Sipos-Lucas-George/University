//
// Created by lukyl on 11/06/2022.
//

#include "Observer.h"

void Subject::notify() {
    for (auto o : this->list)
        o->update();
}
