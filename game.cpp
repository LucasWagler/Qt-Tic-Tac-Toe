// Lucas Wagler
// Dr. Khadka
// 2020-03-11
// Tic-Tac-Toe with Victory Lines

#include "game.h"

game::game()
{


}

void game::click(int button)
{
    if (!state[button]) {
        state[button] = turn;
        turn = (turn == 1) ? 2 : 1;
    }
}

int *game::getState()
{
    return this->state;
}

int game::getTurn()
{
    return turn;
}

int game::winner()
{
    // -1 = tie
    // 0 = ongoing game
    // 1 = player 1 wins
    // 2 = player 2 wins

    // check horizontal
    for (int i = 0; i < 9; i += 3)
    {
        if ( state[i] == state[i+1] and state[i] == state[i+2] and state[i] != 0)
        {
            return state[i];
        }
    }

    // check vertical
    for (int i = 0; i < 3; i++)
    {
        if ( state[i] == state[i+3] and state[i] == state[i+6] and state[i] != 0)
        {
            return state[i];
        }
    }

    // check diagonal NW-SE
    if ( state[0] == state[4] and state[0] == state[8] and state[0] != 0 )
    {
        return state[0];
    }

    // check diagonal NE-SW
    if ( state[2] == state[4] and state[2] == state[6] and state[2] != 0)
    {
        return state[2];
    }

    // check tie
    for (int i = 0; i < 9; i++)
    {
        if (!state[i])
        {
            break;
        }
        if (i == 8)
        {
            return -1;
        }
    }
    return 0;
}

// Dirty implementation for line drawing; could be combined with above winner()
int game::winResult()
{
    // -1 = error
    // 0 = horizontal top
    // 3 = horizontal mid
    // 6 = horizontal bottom
    // 10 = vertical left
    // 11 = vertical mid
    // 12 = vertical right
    // 20 = diagonal NW-SE
    // 21 = diagonal NE-SW

    // check horizontal 0
    for (int i = 0; i < 9; i += 3)
    {
        if ( state[i] == state[i+1] and state[i] == state[i+2] and state[i] != 0)
        {
            return i;
        }
    }

    // check vertical
    for (int i = 0; i < 3; i++)
    {
        if ( state[i] == state[i+3] and state[i] == state[i+6] and state[i] != 0)
        {
            return i+10;
        }
    }

    // check diagonal NW-SE
    if ( state[0] == state[4] and state[0] == state[8] and state[0] != 0 )
    {
        return 20;
    }

    // check diagonal NE-SW
    if ( state[2] == state[4] and state[2] == state[6] and state[2] != 0)
    {
        return 21;
    }

    return -1;
}
