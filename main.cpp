#include <iostream>
#include <cstdlib>
#include "Logic.h"

int main() {
   srand(time(nullptr));
   //TODO: logic
   Logic logic;
   logic.chooseBoard();
   logic.refresh();
   return 0;
}