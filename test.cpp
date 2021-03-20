#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp" 
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;
using ariel::Direction;

ariel::Board board;
Direction h = Direction::Horizontal;
Direction v = Direction::Vertical;

//post and read at a random location
string postNread(Direction dir, string message){
    int row =  getNum(), col = getNum();

    //write post
    board.post(row, col, dir, message);

    //read post
    return board.read(row, col, dir, message.length());
}

// post simple message at (0,0)
void resetMessage(){
    board.post(0, 0, h, "0123456789");
}

//get random number from range
u_int getNum(int from, int to){
    int range = from - to;
    return (rand()%range)+to;
}

u_int getNum(){
    return getNum(0,100);
}

TEST_CASE("Legal input") { // (37 tests)


    // 1) check read unUsed area (1 test)
    CHECK(board.read(0,0,h,10) == "");

    // 2) check read partly used area (1 test)


    /* 3) post and read message in several random locations (20 tests)
          10 vertical + 10 horizontal*/

    string message = "0123456789";
    for(int i = 0; i < 10; i++){
        CHECK(message.compare(postNread(v, message)));
    }

    for(int i = 0; i < 10; i++){
        CHECK(message.compare(postNread(h, message)));
    }

    // 4) check posts over lapping (10 tests)
    /* each iteration another post will be posted on top of "0123456789" like that-
        i=0 message = "a123456789"
        i=1 message = "aa23456789"
        i=2 message = "aaa3456789"
        .
        .
        i=9 message = "aaaaaaaaa"
    */
    resetMessage();
    string messageLapping = "a";
    for(int i = 0; i < 10; i++){
        board.post(0, i, h, messageLapping);
        string newMessage =  messageLapping + message.substr(i, message.length());
        CHECK(newMessage.compare(board.read(0, 0, h, message.length())));
    }

    // 5) read sub message (5 tests)
    int subPostSize = 2;
    resetMessage();
    string subMessage;
    for(int i = 0; i < 10; i+=subPostSize){
        subMessage=to_string(i)+to_string(i+1);
        CHECK(board.read(0, i, h, subPostSize) == subMessage);
    }
}