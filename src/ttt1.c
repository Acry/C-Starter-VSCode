#include <stdlib.h>

#define UNSET 0
#define P1 1
#define P2 2

int main()
{
    // init game
    // clean fields
    int f1 = UNSET;
    int f2 = UNSET;

    int gameRunning = 1;
    int winner = UNSET;
    // which player is playing? p1
    f1 = P1;
    f2 = P2;

    // check if board is full
    if (f1 != UNSET && f2 != UNSET)
    {
        if (f1 == P1 && f2 == P1)
        {
            winner = P1;
        }
        else if (f1 == P2 && f2 == P2)
        {
            winner = P2;
        };
        // if winner is not set the game is a draw
        gameRunning = 0;
    }

    return EXIT_SUCCESS;
}