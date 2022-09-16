#pragma once
#include <cassert>
#include "../Domain/Movie.h"
#include "../Repository/DynamicVector.h"
#include "../Repository/Repository.h"
#include "../Repository/WatchList.h"
#include "../Service/Service.h"

class Tests {
public:
    static void testAll();
    static void testDomain();
    static void testDynamicVector();
    static void testRepository();
    static void testWatchList();
    static void testService();
};
