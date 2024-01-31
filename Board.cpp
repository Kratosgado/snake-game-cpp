#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

int Board::chooseBoard() {
   cout << "Welcome to the Snake game." << endl;
   int choose;
   do {
      try {
         cout << "Choose a board. Available sizes:\n"
            "1. 20x20\n"
            "2. 30x30\n"
            "3. 40x40\n" << endl;
         cout << "What is your choice?: ";
         cin >> choose;
         cout << endl;
         if (choose > 3 || choose < 1) {
            throw("Selected option does not exist");
         }
      }
      catch (char const* e) {
         cin.clear();
         cin.ignore(999, '\n');
         std::system("clear");
         cout << e << endl << endl;
      }
   } while (choose > 3 || choose < 1);
   choose--;
   return choose;
}

void Board::loadBoard() {
   area = new std::string * [SizeX[choose]];

   for (int i = 0; i < SizeX[choose]; i++) {
      area[i] = new std::string[SizeY[choose]];
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
            area[i][j] = charFruit[whichFruit];
         }
         else area[i][j] = "\u2588"; // Full block character

         for (int k = 0; k < bodyX.size(); k++) {
            if (i == bodyY[k] && j == bodyX[k]) {
               area[i][j] = body;
            }
         }
      }
   }
   cout << "Score:" << score << endl;
   cout << "\u250F"; // top left
   for (int i = 0; i < SizeX[choose]; i++) {
      cout << "\u2501"; // side up
   }
   cout << "\u2513" << endl; // top right

   for (int i = 0; i < SizeY[choose]; i++) {
      cout << "\u2503"; // left side
      for (int j = 0; j < SizeX[choose]; j++) {
         cout << area[i][j]; // blank
      }
      cout << "\u2503" << endl; // right side
   }

   cout << "\u2517"; // bottom left
   for (int i = 0; i < SizeX[choose]; i++) {
      cout << "\u2501"; // side bottom
   }
   cout << "\u251B" << endl; // bottom right

}

void Board::cleanUp() {
   for (int i = 0; i < SizeX[choose]; i++) {
      delete[] area[i];
   }
   delete[] area;
}
