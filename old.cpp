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