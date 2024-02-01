#include "Logic.h"
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <csignal>

void Logic::refresh() {
   loadBoard();
   do {
      std::system("clear");
      fruits();
      snake(extend);
      controls();
      printBoard();
      GameOver();
      std::system("sleep 2");
   } while (!isGameOver);
   getchar();
   std::system("clear");
   std::cout << "Final Score: " << score << std::endl;
   cleanUp();
}

void Logic::fruits() {
   if (headX == fruitX && headY == fruitY) {
      switch (whichFruit) {
      case 0:
         score += 5;
         break;
      case 1:
         score += 10;
         break;
      case 2:
         score += 1;
         break;
      }
      extend = true;
      fruit = (rand() % 100);
      fruitX = rand() % SizeX[choose];
      fruitY = rand() % SizeY[choose];
      if (10 > fruit and fruit >= 0) {
         whichFruit = 0;
      }
      else if (21 > fruit and fruit > 10) {
         whichFruit = 1;
      }
      else if (101 > fruit and fruit > 20) {
         whichFruit = 2;
      }
   }
}

void Logic::snake(bool& extend) {
   tempX1 = bodyX[0];
   tempY1 = bodyY[0];
   bodyX[0] = headX;
   bodyY[0] = headY;
   for (int i = 1; i < bodyX.size(); i++) {
      tempX2 = bodyX[i];
      tempY2 = bodyY[i];
      bodyX[i] = tempX1;
      bodyY[i] = tempY1;
      tempX1 = tempX2;
      tempY1 = tempY2;
   }
   if (extend) {
      bodyX.push_back(tempX1);
      bodyY.push_back(tempY1);
      extend = false;
   }
}

void Logic::controls() {
   initscr();
   cbreak();
   noecho();
   nodelay(stdscr, TRUE);

   switch (getch()) {
   case 'a':
      snakeDirection = SnakesDirection::LEFT;
      break;
   case 'd':
      snakeDirection = SnakesDirection::RIGHT;
      break;
   case 'w':
      snakeDirection = SnakesDirection::UP;
      break;
   case 's':
      snakeDirection = SnakesDirection::DOWN;
      break;
   case 'x':
      isGameOver = true;
      break;
   }
   switch (snakeDirection) {
   case SnakesDirection::LEFT:
      headX--;
      break;
   case SnakesDirection::RIGHT:
      headX++;
      break;
   case SnakesDirection::UP:
      headY--;
      break;
   case SnakesDirection::DOWN:
      headY++;
      break;
   }
   endwin();
}

void Logic::GameOver() {
   if (headX == -1 || headX == SizeX[choose] || headY == -1 || headY == SizeY[choose]) {
      isGameOver = true;
   }
   for (int i = 0; i < bodyX.size(); i++) {
      if (headX == bodyX[i] && headY == bodyY[i]) {
         isGameOver = true;
      }
   }
}