#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("Legal input") {
    
    CHECK();
    /* Add more checks here */
}

TEST_CASE("illegal input") {
    CHECK_THROWS(snowman(555));
    /* Add more checks here */
}