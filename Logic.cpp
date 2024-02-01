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
      usleep(200000);
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
         Board::score += 5;
         break;
      case 1:
         Board::score += 10;
         break;
      case 2:
         Board::score += 1;
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
      tempX2 = Board::bodyX[i];
      tempY2 = Board::bodyY[i];
      Board::bodyX[i] = tempX1;
      Board::bodyY[i] = tempY1;
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
   int ch = getch();

   if (ch != ERR) {
      charDirection = ch;
   }

   if (!(charDirection == 'w' || charDirection == 'a' || charDirection == 's' || charDirection == 'd')) {
      charDirection = tempDirection;
   }

   switch (charDirection) {
   case 'w':
      if (tempDirection == 's') { charDirection = 's'; Board::headY++; }
      else {
         tempDirection = charDirection;
         Board::headY--;
      }
      break;
   case 'a':
      std::cout << "a" << std::endl;
      if (tempDirection == 'd') { charDirection = 'd'; Board::headX++; }
      else {
         tempDirection = charDirection;
         Board::headX--;
      }
      break;
   case 's':
      if (tempDirection == 'w') { charDirection = 'w'; Board::headY--; }
      else {
         tempDirection = charDirection;
         Board::headY++;
      }
      break;
   case 'd':
      if (tempDirection == 'a') { charDirection = 'a'; Board::headX--; }
      else {
         tempDirection = charDirection;
         Board::headX++;
      }
      break;
   default:
      break;
   }
   endwin();
}

void Logic::GameOver() {

   if (headX == -1 || headX == SizeX[choose] || headY == -1 || headY == SizeY[choose]) {
      isGameOver = true;
   }
   for (int i = 0; i < Board::bodyX.size(); i++) {
      if (headX == Board::bodyX[i] && headY == Board::bodyY[i]) {
         isGameOver = true;
      }
   }
}