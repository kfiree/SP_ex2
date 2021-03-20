#include "Board.hpp"
#include "Direction.hpp" 
using std::string;



namespace ariel 
{

    Board::Board(){
        
    }

    void post(int row, int column, Direction dir, string txt){

    }

    string read(int row, int column, Direction dir, int len){
         return "";
    }

    void show(){

    }
    
} 
// Board {
//     private:
//         vector<vector<string>> board;
//         int getRow();
//         int getCol();

//     public:
//         // constructor
//         Board();

//         // post massage (given text, direction and location)
//         void post(int row, int column, Direction dir, string txt);

//         // read massage (given length, direction and location)
//         string read(int row, int column, Direction dir, int len);

//         void show();




    // void post(int row, int column, Direction dir, std::string txt);

    // std::string read(int row, int column, Direction dir, int len);

    // void show();