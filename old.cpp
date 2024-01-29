// // this program creates a snake game
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <unistd.h>
// #include <termios.h>
// // #include <ncurses.h>

// using namespace std;

// bool isGameOver;
// const int width = 80;
// const int height = 20;
// int x, y, fruitX, fruitY, score;
// int snakeTailX[100], snakeTailY[100];
// int snakeTailLen;
// enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
// snakesDirection sDir;

// void GameInit();
// void GameRender(string);
// void UpdateGame();
// int SetDifficulty();
// void UserInput();
// char getch();

// int main() {
//    string playerName;

//    cout << "Enter your name: ";
//    cin >> playerName;
//    int difficulty = SetDifficulty();
//    GameInit();
//    while (!isGameOver) {
//       GameRender(playerName);
//       UserInput();
//       UpdateGame();

//       // delay the game according to the chosen difficulty
//       system("sleep 0.1");
//    }
//    return 0;
// }


// // intialize the game
// void GameInit() {
//    isGameOver = false;
//    sDir = STOP;
//    x = width / 2;
//    y = height / 2;
//    fruitX = rand() % width;
//    fruitY = rand() % height;
//    score = 0;
// }

// // Function for creating the game board and rendering
// void GameRender(string playerName) {
//    system("clear");

//    // create top walls with '_' character
//    for (int i = 0; i < width + 2; i++)  cout << "_";

//    cout << endl;

//    for (int i = 0; i < height; i++) {
//       for (int j = 0; j <= width; j++) {
//          // create side walls with '|' character
//          if (j == 0 || j == width) cout << "|";

//          // create snake head with 'O' character
//          if (i == y && j == x) cout << "O";

//          // create fruit with '#' character
//          else if (i == fruitY && j == fruitX) cout << "#";

//          // create snake's head with 'O' character
//          else {
//             bool prTail = false;
//             for (int k = 0; k < snakeTailLen; k++) {
//                if (snakeTailX[k] == j && snakeTailY[k] == i) {
//                   cout << "o";
//                   prTail = true;
//                }
//             }
//             if (!prTail) cout << " ";
//          }
//       }
//       cout << endl;
//    }

//    // create bottom walls with '_' character
//    for (int i = 0; i < width + 2; i++)  cout << "_";
//    cout << endl;
//    // Display player's score
//    cout << playerName << "'s Score: " << score << endl;

// }

// void UpdateGame() {
//    int prevX = snakeTailX[0];
//    int prevY = snakeTailY[0];
//    int prev2X, prev2Y;
//    snakeTailX[0] = x;
//    snakeTailY[0] = y;
//    for (int i = 1; i < snakeTailLen; i++) {
//       prev2X = snakeTailX[i];
//       prev2Y = snakeTailY[i];
//       snakeTailX[i] = prevX;
//       snakeTailY[i] = prevY;
//       prevX = prev2X;
//       prevY = prev2Y;
//    }

//    switch (sDir) {
//    case LEFT:
//       x--;
//       break;
//    case RIGHT:
//       x++;
//       break;
//    case UP:
//       y--;
//       break;
//    case DOWN:
//       y++;
//       break;
//    }

//    // checks for snake's collision with the wall (|)
//    if (x >= width || x < 0 || y >= height || y < 0) isGameOver = true;

//    // checks for snake's collision with the tail (o)
//    for (int i = 0; i < snakeTailLen; i++) {
//       if (snakeTailX[i] == x && snakeTailY[i] == y) isGameOver = true;
//    }

//    // checks for snake's collision with the fruit (#)
//    if (x == fruitX && y == fruitY) {
//       score += 10;
//       fruitX = rand() % width;
//       fruitY = rand() % height;
//       snakeTailLen++;
//    }
// }

// int SetDifficulty() {
//    int difficulty, choice;
//    cout << "\n SET DIFFICULTY \n 1. Easy \n 2. Medium \n 3. Hard \n 4. Extreme \n 5. Impossible \n"
//       "\n NOTE: if not chosen the default difficulty is set to Easy \n";
//    cin >> choice;
//    switch (choice) {
//    case 1:
//       difficulty = 50;
//       break;
//    case 2:
//       difficulty = 100;
//       break;
//    case 3:
//       difficulty = 150;
//       break;
//    case 4:
//       difficulty = 200;
//       break;
//    default:
//       difficulty = 50;
//       break;
//    }
//    return difficulty;
// }

// void UserInput() {
//    // initscr();
//    // cbreak();
//    // noecho();
//    // nodelay(stdscr, TRUE);
//    // checks for a key pressed on linux

//    switch (getch()) {
//    case 'a':
//       sDir = LEFT;
//       break;
//    case 'd':
//       sDir = RIGHT;
//       break;
//    case 'w':
//       sDir = UP;
//       break;
//    case 's':
//       sDir = DOWN;
//       break;
//    case 'x':
//       isGameOver = true;
//       break;
//    }
// }

// char getch() {
//    char buf = 0;
//    struct termios old = { 0 };
//    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
//    old.c_lflag &= -ICANON;
//    old.c_lflag &= -ECHO;
//    old.c_cc[VMIN] = 1;
//    old.c_cc[VTIME] = 0;
//    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
//    if (read(0, &buf, 1) < 0) perror("read()");
//    old.c_lflag |= ICANON;
//    old.c_lflag |= ECHO;
//    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr -ICANON");
//    return(buf);
// }