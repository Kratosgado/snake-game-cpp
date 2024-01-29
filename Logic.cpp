#include "Logic.h"
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <csignal>

void Logic::refresh() {
   Logic::loadBoard();
   do {
      std::system("clear");
      // fruits();
      // snake(extend);
      // controls();
      Board::printBoard();
      // GameOver();
      usleep(200000);
   } while (!isGameOver);
   std::system("clear");
   std::cout << "Final Score" << score << std::endl;
   // Board::cleanUp();
}