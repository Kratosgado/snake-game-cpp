#pragma once
#include "Board.h"

class Logic : public Board {
protected:
   bool isGameOver = false, extend = false;
   int fruit = 0, tempX1 = 0, tempY1 = 0, tempX2 = 0, tempY2 = 0;
   char charDirection = 'w', tempDirection = 'w';

public:
   void refresh();
   // void snake(bool& extend);
   // void controls();
   // void fruits();
   // void GameOver();
};