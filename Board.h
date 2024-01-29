#pragma once
#include <cstdlib>
#include <vector>
#include <string>

class Board
{
protected:
   const int SizeX[3] = {20, 30, 40};
    const int SizeY[3] = {20, 30, 40};
    int choose = 0, score = 0, fruitX = 5, fruitY = 5, headX = 0, headY = 0;
    std::string** area;
    std::vector<int> bodyX, bodyY;
    char head = 'O', body = 'o', temp = 0;
    char charFruit = '#';
public:
   int chooseBoard();
   void loadBoard();
   void printBoard();
   void cleanUp();
};
