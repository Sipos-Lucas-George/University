#pragma once
#include <cassert>
#include <vector>
#include "../Domain/Movie.h"
#include "../Repository/Repository.h"
#include "../Repository/WatchList.h"
#include "../Service/Service.h"
#include "../ExceptionsValidators/Exceptions.h"
#include "../ExceptionsValidators/Validator.h"

class Tests {
public:
    static void testAll();
    static void testDomain();
    static void testRepository();
    static void testWatchList();
    static void testService();
};
