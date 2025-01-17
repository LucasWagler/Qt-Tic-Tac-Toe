// Lucas Wagler
// Dr. Khadka
// 2020-03-11
// Tic-Tac-Toe with Victory Lines

#ifndef GAME_H
#define GAME_H

#include <array>

class game
{
private:
    int state[9] = {0,0,0,0,0,0,0,0,0};
    int turn = 1;
public:
    game();
    void click(int button);
    int *getState();
    int getTurn();
    int winner();
    int winResult();
};

#endif // GAME_H
