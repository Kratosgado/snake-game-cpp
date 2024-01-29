#include "Board.h"
#include <iostream>

using namespace std;

int Board::chooseBoard() {
   cout << "Welcome to the snake game." << endl;
   int choose;
   do {
      try {
         cout << "Choose a board. Available sizes: \n"
            "1. 20x20\n"
            "2. 30x30\n"
            "3. 40x40\n" << endl;
         cout << "What is your choice?:";
         cin >> choose;
         cout << endl;
         if (choose > 3 || choose < 1) throw("Selected option does not exit");
      }
      catch (char const* e) {
         cin.clear();
         cin.ignore(999, '\n');
         system("clear");
         cout << e << endl << endl;
      }
   } while (choose > 3 || choose < 1);
   choose--;
   return choose;
}

void Board::loadBoard() {
   area = new string * [SizeX[choose]];
   for (int i = 0; i < SizeX[choose]; i++) {
      area[i] = new string[SizeY[choose]];
   }
   headX = SizeX[choose] / 2;
   headY = SizeY[choose] / 2;
   bodyX.push_back(headX + 1);
   bodyY.push_back(headY);
}

void Board::printBoard() {
   for (int i = 0; i < SizeX[choose]; i++) {
      for (int j = 0; j < SizeY[choose]; j++) {
         if (i == headY && j == headX) {
            area[i][j] = head;
         }
         else if (i == fruitY && j == fruitX) {
            area[i][j] = charFruit;
         }
         else area[i][j] = "\u2588"; // Full block character

         for (int k = 0; k < bodyX.size(); k++) {
            if (i == bodyY[k] && j == bodyX[k]) {
               area[i][j] = body;
            }
         }
      }
   }
}